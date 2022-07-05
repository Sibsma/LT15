

all:book

book: main.o book.o cmd.o
	gcc main.o book.o cmd.o -o book

main.o: main.c
	gcc -c main.c

book.o: book.c
	gcc -c book.c

cmd.o: cmd.c
	gcc -c cmd.c

clean:
	rm -rf *.o book


