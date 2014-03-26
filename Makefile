build: curly
curly: objs
	gcc main.c -lcurl -ljansson measurement.o -o curly
objs:
	gcc -c measurement.c
clean:
	rm -f curly *.o
