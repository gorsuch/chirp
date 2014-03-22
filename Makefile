build: curly jcurly
curly: objs
	gcc main.c -l curl measure.o -o curly
jcurly: objs
	gcc jcurly.c -l curl measure.o -o jcurly
objs:
	gcc -c measure.c
clean:
	rm -f curly *.o
