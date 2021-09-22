NAME = pipex

LIB_PATH = libft/

CFILES = \
			ft_child_1.c\
			ft_child_2.c\
			ft_free_struct.c\
			ft_init.c\
			pipex.c\

OBJECTS = $(CFILES:.c=.o)

CC = gcc

DEBUG = clang

CFLAGS = -Wall -Werror -Wextra

DEBUGFLAGS = -g

FILE = output.txt

all: subsystem $(NAME)

subsystem:
	make -C $(LIB_PATH) all

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIB_PATH)libft.a -o $(NAME)

clean:
	make -C $(LIB_PATH) clean
	rm -f $(OBJECTS)

fclean: clean
	make -C $(LIB_PATH) fclean
	rm -f $(NAME)

re: fclean all

call: all clean
	make -C $(LIB_PATH) fclean
	[[ -f $(FILE) ]] && rm $(FILE) || true

d:
	$(DEBUG) $(DEBUGFLAGS) $(CFILES) $(LIB_PATH)*.c -o debug
	lldb debug

clean_d:
	rm -f debug
