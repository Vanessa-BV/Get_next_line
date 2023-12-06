#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_data
{
	char	*line;
	int		nl_index;
}	t_data;

char	*get_next_line(int fd);
int		buffer_to_line(t_data *data, char *buffer);
int		string_char(const char *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
int		trim_line(t_data *data);
int		read_and_stash(t_data *data, int fd, char *buffer);
char	*ft_strjoin(char const *s1, char const *s2);
#endif
