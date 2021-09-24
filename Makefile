NAME = pipex

LIB_PATH = libft/

LIB = $(LIB_PATH)libft.a

CFILES = \
			ft_child_1.c\
			ft_child_2.c\
			ft_free_struct.c\
			ft_get_path.c\
			ft_init.c\
			pipex.c\

OBJECTS = $(CFILES:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

FILE = output

all: subsystem $(NAME)

subsystem:
	make -C $(LIB_PATH) all

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIB) -o $(NAME)

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
