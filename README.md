# Codam Rank 01

# get_next_line

## Goals
The "get_next_line" project aims to enhance the C programming skills by implementing a function that reads text files or standard input, one line at a time. Additionally, it provides an opportunity to grasp the concept of static variables in C programming.

## Function prototype
``` char *get_next_line(int fd); ```

## Mandatory Part
Repeated calls to the get_next_line() function should allow the user to read the text file pointed to by the file descriptor, retrieving one line at a time.
The function should return the line that was read. If there is nothing else to read or if an error occurs, it should return NULL.
Ensure the function operates correctly when reading from both a file and standard input.
The returned line should include the terminating \n character, except if the end of the file was reached and it does not end with a \n character.
The header file get_next_line.h must contain at least the prototype of the get_next_line() function.
All necessary helper functions should be added in the get_next_line_utils.c file.
To enable reading files in get_next_line(), include the option -D BUFFER_SIZE=n in the compiler call, where n defines the buffer size for read().
