build: curly jcurly
curly: objs
	gcc main.c -lcurl -ljansson measure.o -o curly
jcurly: objs
	gcc jcurly.c -lcurl -ljansson measure.o -o jcurly
objs:
	gcc -c measure.c
clean:
	rm -f curly *.o
