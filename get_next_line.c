#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*line;
	static t_list	*stash;
	int				no_char_read;

	if (fd == -1 || BUFFER_SIZE < 0 || read(fd, &line, 0) == -1)
		return NULL;
	no_char_read = 1;
	line = NULL;
	// 1. read from fd and add to linked list
	read_and_stash(fd, &stash, &no_char_read);
	if (stash == NULL)
		return (NULL);
	// 2. extract from stash to line
	extract_line(stash, &line);
	// 3. clean up stash
	clean_stash(&stash);
	if (line[0] == '\0')
	{
		free_stash(stash);
		stash = NULL;
		return (NULL);
	}
	return (line);
}

/*uses read() to add characters to the stash*/
void	read_and_stash(int fd, t_list **stash, int *no_char_read)
{
	char	*buff;

	while (!found_newline(*stash) && no_char_read != 0)
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buff == NULL)
			return;
		*no_char_read = (int)read(fd, buff, BUFFER_SIZE); //int returns size_t, hence typecasting to int here - but maybe not even necessary..to be tested
		if ((*stash == NULL && *no_char_read == 0) || *no_char_read == -1)
		{
			free(buff);
			return;
		}
		buff[*no_char_read] = '\0';
		add_to_stash(stash, buff, *no_char_read);
		free(buff);
	}
}

/*adds content of our buffer to the end of our stash*/
void	add_to_stash(t_list **stash, char *buff, int no_char_read)
{
	int		i;
	t_list	*last;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->content = malloc(sizeof(char) * (no_char_read + 1));
	if (new_node->content == NULL)
		return;
	i = 0;
	while (buff[i] && i < no_char_read)
	{
		new_node->content[i] = buff[i]; //copy into the new node everything from the buffer that has been read
		i++;
	}
	new_node->content[i] = '\0';
	if (*stash == NULL)
	{
		*stash = new_node;
		return ;
	}
	last = ft_lst_get_last(*stash);
	last->next = new_node;
}

/*extracts all characters from our stash and stores them in our line*/
/*stopping after the first '\n' it encounters*/
void	extract_line(t_list *stash, char **line)
{
	int	i;
	int	j;

	if (stash == NULL)
		return ;
	generate_line(line, stash); //sends pointer on pointer to the line that was the first one mentioned in the GNL function above. it will take here a pointet to pointer to char
	if (*line == NULL)
		return ;
	j = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				(*line)[j++] = stash->content[i];
				break;
			}
			(*line)[j++] = stash->content[i++];
		}
		stash = stash->next;
	}
	(*line)[j] = '\0';
}

/*After extracting the line that was read, we do not need those characters anymore.
This function clears the stash so only the characters that have not been returned at
the end of get_next_line() remain in our static stash*/
void	clean_stash(t_list **stash)
{
	t_list	*last;
	t_list	*clean_node;
	int		i;
	int		j;

	clean_node = malloc(sizeof(t_list));
	if (stash == NULL || clean_node == NULL)
		return;
	clean_node->next = NULL;
	last = ft_lst_get_last(*stash);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content && last->content[i] == '\n')
		i++;
	clean_node->content = malloc(sizeof(char) * (ft_strlen(last->content) - i) + 1); //the length of all characters that are in the last element of my stash - the number of characters that have just been counted, since these are the characters that have already been returned. so only the characters will be left that will be kept. +1 for null terminator
	if (clean_node->content == NULL)
		return;
	j = 0;
	while (last->content[i])
		clean_node->content[j++] = last->content[i++];
	clean_node->content[j] = '\0';
	free_stash(*stash);
	*stash = clean_node;
}

int	main(void)
{
	int		file_descriptor;
	char	*line;

	file_descriptor = open("file", O_RDONLY);
	line = get_next_line(file_descriptor);
	if (file_descriptor == -1)
	{
		printf("File could not be opened.\n");
		return -1;
	}
	if (line == NULL)
		printf("No line could be printed.\n");
	else
		printf("%s\n", line);
	close(file_descriptor);
	free (line);
	return (0);
}
