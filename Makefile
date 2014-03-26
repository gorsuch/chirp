build: curly
curly: objs
	gcc main.c -lcurl -ljansson check.o measurement.o -o curly
objs:
	gcc -c measurement.c check.c
clean:
	rm -f curly *.o
