#include <stdio.h>
#include "singlinklist.h"
#include "interface.h"

/* Funcao de criacao de uma interface para o programa. Nao recebe parametros
 * Tem tipo de retorno void
 */
void main_interface(void) {
    struct paciente* lista = cria_lista();

    // variavel para segurar a opcao de prosseguimento da interface, contador
    // de ordem de chegada, e array de contador de cada prioridade
    int priority_temp = -1;
    int* priority_ptr = &priority_temp;
    int opcao = -1, i = 1, ordem = 0;
    int counters[3];

    do {
        printf("Numero de pacientes, vermelha: %d; amarela: %d; verde: %d\n", counters[0], counters[1], counters[2]);
        // variaveis para segurar os valores de input do usuario
        int priority = -1, ordem = 0;
	printf("Insira sua opcao (0: inserir paciente, 1: atender paciente, 2: paciente transferido, 3: paciente desistiu, 4: imprimir lista, 5: finalizar): ");
        scanf("%d", &opcao);
        switch(opcao) {
            case 0:
		do {
                    printf("Insira o nivel de prioridade (VERMELHO: 0, AMARELO: 1, VERDE: 2): "); 
		    scanf("%d", &priority); 
		} while (priority < 0 || priority > 2);

		counters[priority] += 1;
                lista = chegada(lista, priority, i);
                i++;
                break;
            case 1:
		if (lista != NULL)
		    counters[lista->priority] -= 1;
		lista = atende(lista, 1);
                break;
	    case 2:
		do {
		    printf("Insira o nivel de prioridade (VERMELHO: 0, AMARELO: 1, VERDE: 2): ");
		    scanf("%d", &priority);
		} while (priority < 0 || priority > 2);
		lista = desiste_ou_transfere(lista, priority, 0, priority_ptr);
	        if (counters[priority_temp] != 0 && priority_temp >= 0)
	            counters[priority_temp] -= 1;
		break;
	    case 3:
	        printf("Insira a ordem de chegada do paciente: ");
	        scanf("%d", &ordem);
	        lista = desiste_ou_transfere(lista, ordem, 1, priority_ptr);
	        if (counters[priority_temp] != 0 && priority_temp >= 0)
	            counters[priority_temp] -= 1;
		break;
	    case 4:
		imprime(lista);
		break;
	    case 5:
		printf("Finalizando...\n");
    		libera_lista(lista);
		return;
	    default:
		printf("Insira uma opcao valida!\n");
		continue;
        }
    } while (opcao != 5);
}
