build: objs
	gcc main.c -l curl measure.o -o curly
objs:
	gcc -c measure.c
clean:
	rm -f curly *.o
