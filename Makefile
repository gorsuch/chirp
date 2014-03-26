build: curly
curly: objs
	gcc main.c -lcurl -ljansson measure.o -o curly
objs:
	gcc -c measure.c
clean:
	rm -f curly *.o
