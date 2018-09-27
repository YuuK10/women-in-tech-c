NAME="game"
SRC=src/*.c
INCLUDES=includes

all: $(NAME)

$(NAME): 
	gcc -c -I $(INCLUDES) $(SRC)
	gcc -o $(NAME) *.o

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean, all
