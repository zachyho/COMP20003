autocomplete1: autocomplete1.o Skeleton.o definitions.h
	gcc -Wall -o autocomplete1 autocomplete1.o Skeleton.o -g


autocomplete1.o: autocomplete1.c definitions.h
	gcc -Wall -c autocomplete1.c -g

Skeleton.o: Skeleton.c definitions.h
	gcc -Wall -c Skeleton.c -g
