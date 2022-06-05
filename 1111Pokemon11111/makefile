SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all: exec

%.o : %.c pokemon.h
	gcc -c $< -o $@

exec: $(OBJ)
	gcc $^ -o $@

clean :
	rm -f *.o
	rm exec
