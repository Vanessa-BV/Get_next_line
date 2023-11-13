#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

# ifndef BUFFFER_SIZE
#	define BUFFER_SIZE 5
# endif

typedef struct Node
{
	char		*content;
	struct Node	*next;
}	t_list;

char	*get_next_line(int fd);
