#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//for read(), open(), close()
# include <unistd.h>
# include <fcntl.h>
// for printf
# include <stdio.h>
// for malloc() and free()
# include <stdlib.h>
// for boolean
# include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
char	*read_and_stash(int fd, char *buffer, char *str_stash);
char	*stash_to_line(char *str_stash);
void	update_stash(char *str_stash);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *str);
size_t	newline_index(const char *s);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	free_all(char **str);
#endif
