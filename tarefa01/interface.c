#include <stdio.h>
#include "operacoes.h"
#include "paciente.h"
#include "interface.h"

// Funcai para fornecer uma interface que permite ao usuario inserir pacientes, 
// atende-los, removendo-os, além de finalizar, em cujo caso a lista e liberada
// e o programa volta para a main()
void main_interface(void) {
    struct paciente* lista = cria_lista();

    // variavel para segurar a opcao de prosseguimento da interface, contador
    // de ordem de chegada, e array de contador de cada prioridade
    int opcao = -1;
    int i = 1;
    int counters[3];

    do {
        printf("Numero de pacientes, vermelha: %d; amarela: %d; verde: %d\n", counters[0], counters[1], counters[2]);
        int priority = 0;
	printf("Insira sua opcao (0: inserir paciente, 1: atender paciente, 2: encerrar execucao): ");
        scanf("%d", &opcao);
        switch(opcao) {
            case 0:
		do {
                    printf("Insira o nivel de prioridade (VERMELHO: 0, AMARELO: 1, VERDE: 2): "); 
		    scanf(" %d", &priority); 
		} while (priority < 0 || priority > 2);

		counters[priority] += 1;
                lista = chegada(lista, priority, i);
                i++;
                break;
            case 1:
		if (lista != NULL)
		    counters[lista->priority] -= 1;
		lista = atende(lista);
                break;
	    case 2:
		printf("Finalizando...\n");
		return;
	    default:
		printf("Insira uma opcao valida!\n");
		continue;
        }
    } while (opcao != 2);
    libera_lista(lista);
}
