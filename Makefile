NAME = get_next_line.a

SOURCES_MAND = get_next_line.c \
				get_next_line_utils.c \
				get_next_line.h

OBJS_MAND = $(SOURCES_MAND:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar

all: $(NAME)

$(NAME): $(OBJS_MAND)
	$(AR) rcs $(NAME) $(OBJS_MAND)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS_MAND)

fclean:clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re