SRC	=	$(shell find ./src -name "*.c")
OBJ	=	$(SRC:.c=.o)
CC	= 	gcc
RM	=	rm -rf
INCLUDE	=	./include
EXE	=	packet_catcher
CFLAGS	=	-W -Wall -Werror -Wextra -I $(INCLUDE)
DEBUG_FLAGS	=	-g -ggdb -g3

all: $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(EXE)

debug:
	$(CC) $(SRC) $(CFLAGS) $(DEBUG_FLAGS) -o $(EXE)
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(EXE)

re: fclean all