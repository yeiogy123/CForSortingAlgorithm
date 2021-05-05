all:main.o myheapsort.o mymergesort.o myquicksort.o
	gcc -g main.o myheapsort.o mymergesort.o myquicksort.o -o main
main.o:
	gcc -c main.c -o main.o
myheapsort.o:
	gcc -c myheapsort.c -o myheapsort.o
mymergesort.o:
	gcc -c mymergesort.c -o mymergesort.o
myquicksort.o:
	gcc -c myquicksort.c -o myquicksort.o
clean:
	rm -f myquicksort.o mymergesort.o myheapsort.o main.o main
