NAME = pipex

FLAGS = -Wall -Wextra -Werror

SRCS = main.c pipex.c path.c util.c

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	gcc $(FLAGS) -o $@ $^

%.o:%.c
	gcc $(FLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all