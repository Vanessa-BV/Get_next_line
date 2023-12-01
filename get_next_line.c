#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (stash != NULL && ft_strchr(stash, '\n') != NULL)
		line = stash_to_line(stash);
	else
	{
		buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (buffer == NULL)
			return (free_all(&stash), NULL);
		stash = read_and_stash(fd, buffer, stash);
		if (stash == NULL)
			return (free_all(&buffer), NULL);
		free_all(&buffer);
		line = stash_to_line(stash);
	}
	if (line == NULL)
		return (free_all(&stash), NULL);
	update_stash(stash);
	if (*line == '\0')
		return(free_all(&line), NULL);
	return (line);
}

char	*read_and_stash(int fd, char *buffer, char *str_stash)
{
	int		bytes_read;
	char	*temp_stash;

	bytes_read = 1;
	if (str_stash == NULL)
		str_stash = ft_strdup("");
	if (str_stash == NULL)
		return (NULL);
	while (bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return(free_all(&str_stash), NULL);
		buffer[bytes_read] = '\0';
		temp_stash = str_stash;
		str_stash = ft_strjoin(temp_stash, buffer);
		if (str_stash == NULL)
			return (free_all(&temp_stash), NULL);
		free_all(&temp_stash);
		if (ft_strchr(str_stash, '\n') != NULL)
			break ;
	}
	return (str_stash);
}

char	*stash_to_line(char *str_stash)
{
	size_t	i;
	char	*str_line;

	i = 0;
	str_line = (char *)malloc((newline_index(str_stash) + 2) * sizeof(char));
	if (str_line == NULL)
		return (NULL);
	while ((str_stash[i]) && str_stash[i] != '\n')
	{
		str_line[i] = str_stash[i];
		if (str_line[0] == '\0')
			return (free_all(&str_line), NULL);
		i++;
	}
	if (str_stash[i] == '\n')
		str_line[i++] = '\n';
	str_line[i] = '\0';
	return (str_line);
}

void	update_stash(char *str_stash)
{
	// size_t	newline_index;
	char	*source;
	size_t	i;

	i = 0;
	source = ft_strchr(str_stash, '\n');
	if (source == NULL)
	{
		free_all(&str_stash);
		return ;
	}
	source++;
	while (source[i] != '\0')
	{
		str_stash[i] = source[i];
		i++;
	}
	str_stash[i] = '\0';
	i++;
	while (str_stash[i] != '\0')
	{
		str_stash[i] = '\0';
		i++;
	}
	// newline_index = 0;
	// while (str_stash[newline_index] != '\n')
	// 	newline_index++;
	
	// ft_memmove(str_stash, str_stash + newline_index + 1,
	// 	(ft_strlen(str_stash) - newline_index) * sizeof(char));
	
}

void	free_all(char **str)
{
	if (str != NULL && *str != NULL)
	{
		free(*str);
	}
	*str = NULL;
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("1char.txt", O_RDONLY);
// 	if (fd < 0)
// 	{
// 		printf("Error ocurred while opening the file.\n");
// 		return (1);
// 	}
// 	for (int i = 0; i < 5; i++)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		free (line);
// 	}
// 	// while ((line = get_next_line(fd)) != NULL)
// 	// {
// 	// 	printf("%s", line);
// 	// 	free_all(&line);
// 	// }
// 	close(fd);
// 	return (0);
// }

