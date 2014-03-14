CC = gcc
EXEC = string

${EXEC}: main.o new_string.o
	${CC} main.o new_string.o -o ${EXEC}

main.o: main.c
	${CC} -c main.c -o main.o

new_string.o: new_string.c
	${CC} -c new_string.c -o new_string.o

clean:
	rm -f *.o ${EXEC}
