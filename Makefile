CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -I -MMD
LDFLAGS = -lncursesw
NAME = htop_eco+
SRC = main.c services.c utils.c ui.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

run: re
	./$(NAME)

.PHONY: all clean fclean re run