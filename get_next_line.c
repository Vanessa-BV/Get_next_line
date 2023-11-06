#include "get_next_line.h"

char	*get_next_line(int fd)
{
/*** allocate memory for buffer (malloc) ***/

/*** read file (read) ***/
// implement logic to not read a binary file
// protoype read(): "ssize_t	read(int fildes, void *buf, size_t nbyte);"

/*** free memory (free) ***/
}

int	main(void)
{
	int	file_descriptor;

	file_descriptor = open("file", O_RDONLY);
	if (file_descriptor == -1)
	{
		printf("File could not be opened.\n");
		return -1;
	}
	close(file_descriptor);
	return (0);
}