NAME="game"
SRC=src/*.c
INCLUDES=includes

all: $(NAME)

$(NAME):
	@gcc -c -I $(INCLUDES) $(SRC)
	@gcc -o $(NAME) *.o -lncurses -lpthread

clean:
	@rm -rf *.o 2>&1 > /dev/null

fclean: clean
	@rm -rf $(NAME) 2>&1 > /dev/null

re: fclean all
