NAME = pipex

CFILES =	ft_calloc.c\
			ft_child_1.c\
			ft_child_2.c\
			ft_init.c\
			ft_parent_process.c\
			ft_split.c\
			ft_strjoin.c\
			pipex.c\

OBJECTS = ($(CFILES):.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra -c

all: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
