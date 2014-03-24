build: curly
curly: objs
	gcc main.c -lcurl -ljansson -lhiredis measure.o -o curly
objs:
	gcc -c measure.c
clean:
	rm -f curly *.o
