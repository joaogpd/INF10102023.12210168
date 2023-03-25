main: singlinklist.o interface.o main.o
	gcc -o main singlinklist.o interface.o main.o
	rm singlinklist.o interface.o main.o

singlinklist.o: singlinklist.c
	gcc -c singlinklist.o singlinklist.c
   
interface.o: interface.c
	gcc -c interface.o interface.c

main.o: main.c
	gcc -c main.o main.c


