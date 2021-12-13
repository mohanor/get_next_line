CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC = get_next_line.c


OBJ = $(SRC:.c=.o)

all : $(NAME)

clean :
	rm -rf $(OBJ) $(bonus_obj)
fclean : clean
	rm -rf $(NAME)

re : fclean all