#include "get_next_line.h"

int	trim_line(t_data *data)
{
	char	*new_line;

	data->nl_index = string_char(data->line, '\n');
	if (data->nl_index == -1)
		return (0);
	new_line = (char *)malloc((data->nl_index + 2) * sizeof(char));
	if (new_line == NULL)
		return (-1);
	ft_strlcpy(new_line, data->line, data->nl_index + 2);
	free(data->line);
	data->line = new_line;
	return (0);
}

int	buffer_to_line(t_data *data, char *buffer)
{
	char	*str;

	str = (char *)malloc((ft_strlen(buffer) + 1) * sizeof(char));
	if (str == NULL)
		return (-1);
	data->line = str;
	data->nl_index = string_char(buffer, '\n');
	if (data->nl_index == -1)
		ft_strlcpy(str, buffer, ft_strlen(buffer) + 1);
	else
		ft_strlcpy(str, buffer, data->nl_index + 2);
	return (0);
}

int	read_and_stash(t_data *data, int fd, char *buffer)
{
	int		bytes_read;
	char	*temp;

	bytes_read = 1;
	while (bytes_read != 0 && string_char(buffer, '\n') == -1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (-1);
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(data->line, buffer);
		if (temp == NULL)
			return (-1);
		free(data->line);
		data->line = temp;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	t_data		data;
	static char	buffer[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (buffer_to_line(&data, buffer) == -1)
		return (NULL);
	if (read_and_stash(&data, fd, buffer) == -1)
	{
		buffer[0] = '\0';
		return (free(data.line), NULL);
	}
	if (trim_line(&data) == -1)
		return (free(data.line), NULL);
	data.nl_index = string_char(buffer, '\n');
	if (data.nl_index != -1)
		ft_strlcpy(buffer, &buffer[data.nl_index + 1], \
		ft_strlen(&buffer[data.nl_index + 1]) + 1);
	if (data.line[0] == '\0')
		return (free(data.line), NULL);
	return (data.line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("giant_line.txt", O_RDONLY);
// 	if (fd < 0)
// 	{
// 		printf("Error ocurred while opening the file.\n");
// 		return (1);
// 	}
// 	// for (int i = 0; i < 10; i++)
// 	// {
// 	// 	line = get_next_line(fd);
// 	// 	printf("%s", line);
// 	// 	free (line);
// 	// }
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		if (line == NULL)
// 			break ;
// 		free (line);
// 	}
// 	close(fd);
// 	return (0);
// }
