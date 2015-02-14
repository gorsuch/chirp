build: chirp
chirp: objs
	gcc main.c -lcurl measurement.o -o chirp
objs:
	gcc -c measurement.c
clean:
	rm -f chirp *.o
install: build
	cp ./chirp /usr/local/bin

