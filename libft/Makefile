NAME = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

CFILES = \
		ft_calloc.c\
		ft_free_array.c\
		ft_split.c\
		ft_strchr.c\
		ft_strdup.c\
		ft_strjoin.c\
		ft_strlen.c\
		ft_substr.c\

OBJECTS = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rcs $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
