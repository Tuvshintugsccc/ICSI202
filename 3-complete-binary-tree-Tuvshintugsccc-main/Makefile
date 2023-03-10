all: cbt

cbtree.o: cbtree.c DS.h
	gcc -c cbtree.c -o cbtree.o

main.o: main.c DS.h
	gcc -c main.c -o main.o

cbt: cbtree.o main.o
	gcc cbtree.o main.o -o cbt

clean:
	rm -v *.o cbt
