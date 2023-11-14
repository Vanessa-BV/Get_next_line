#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

typedef struct Node
{
	char		*content;
	struct Node	*next;
}	t_list;

char	*get_next_line(int fd);
int		found_newline(t_list *stash);
t_list	*ft_lst_get_last(t_list *stash);
void	generate_line(char **line, t_list *stash);
void	free_stash(t_list *stash);
int		ft_strlen(const char *str);
void	ft_read_and_stash(int fd, t_list **stash);
void	add_to_stash(t_list **stash, char *buff, int no_char_read);
void	extract_line(t_list *stash, char **line);
void	clean_stash(t_list **stash);
char	*get_next_line(int fd);
#endif