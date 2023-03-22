main: operacoes.o interface.o paciente.o main.o
	gcc -o main *.o
	rm -f *.o

operacoes.o: operacoes.c
	gcc -c operacoes.o operacoes.c
   
interface.o: interface.c
	gcc -c interface.o interface.c

paciente.o: paciente.c
	gcc -c paciente.o paciente.c
    
main.o: main.c
	gcc -c main.o main.c


