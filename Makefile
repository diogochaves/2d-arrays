CC			=	gcc
FLAGS		=	-Wall -Werror -Wall
NAME		=	2d-arrays

SRC_FILES	=	2d-arrays.c

build:
	$(CC) $(FLAGS) -o $(NAME) $(SRC_FILES)

run:
	./2d-arrays

val:
	valgrind ./2d-arrays

clean:
	rm $(NAME)	

.PHONY: build run val clean
