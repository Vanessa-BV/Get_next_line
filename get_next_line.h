#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

# ifndef BUFFFER_SIZE
#	define BUFFER_SIZE 5
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);