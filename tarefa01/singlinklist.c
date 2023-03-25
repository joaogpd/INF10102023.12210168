// 2210168 - Joao Gabriel Peixoto Drumond Lopes

#include <stdio.h>
#include <stdlib.h>
#include "singlinklist.h"

// tipo enum Priority, define as prioridades de atendimento
enum Priority;

// tipo estruturado paciente
struct paciente;

/* Cria uma nova instancia de um struct paciente*, alocando a memoria necessaria. Recebe os parametros
 * um enum Priority, que indica a prioridade do paciente,
 * um int o, que indica a ordem de chegada do paciente.
 * Retorna um struct paciente*, um no de lista encadeada
 * O valor de novo->next e NULL por default, e pode ser alterado na implementacao
 */
struct paciente* cria_paciente(enum Priority r, int o) {
    struct paciente* novo = (struct paciente*)malloc(sizeof(struct paciente));
    if (novo == NULL) return NULL;
    novo->priority = r;
    novo->order = o;
    novo->next = NULL;
    return novo;
}

/* Funcao de remocao de no de lista encadadeada. Recebe como parametros:
 * um struct paciente*, a lista que vai ser manipulada,
 * um int input, o valor a ser retirado, 
 * o int desiste (flag para indicar se e uma desistencia ou uma transferencia),
 * o int* priority, utilizado para obter o valor da prioriade do no retirado
 * Retorna a lista atualizada, um struct paciente*
 */
struct paciente* desiste_ou_transfere(struct paciente* l, int input, int desiste, int* priority) {
    struct paciente* h = NULL;
    struct paciente* p = l;
    
    while (p != NULL && (desiste ? (p->order != input) : (p->priority != input))) {
        h = p;
        p = p->next;
    }
    	
    if (p == NULL)
	return l;
    
    if (h == NULL) {
        l = p->next;
	free(p);
	return l;
    }
    h->next = p->next;
    *priority = p->priority;
    free(p);
    
    imprime(l);
    
    return l;
}


/* Funcao de criacao de lista encadadeada. Nao recebe parametros
 * Retorna NULL
 */
struct paciente* cria_lista(void) {
    return NULL;
}

/* Funcao de insercao em lista encadaeada mantendo ordenacao. Recebe como parametros
 * um struct paciente*, a lista a ser manipulada,
 * um enum Priority r, que indica o nivel de prioridade do paciente a ser inserido,
 * um int o, que indica a ordem de chegada do paciente a ser inserido
 * Retorna a lista atualizada, um struct paciente*
 */
struct paciente* chegada(struct paciente* l, enum Priority r, int o) {
    struct paciente* novo = cria_paciente(r, o);
    if (novo == NULL) {
        fprintf(stderr, "Erro ao alocar memoria");
	exit(1);
    }
    // lista vazia
    if (l == NULL) {
	l = novo;
	return l;
    }
    struct paciente* h = NULL;
    struct paciente* p = l;
    while (p != NULL && p->order < o && p->priority <= r) {
        h = p;
	p = p->next;
    }
    if (h == NULL) {
	novo->next = p;
	l = novo;
	return l;
    }
    h->next = novo;
    novo->next = p;
    return l;    
}    

/* Funcao de impressao de lista encadeada. Recebe como parametro
 * um struct paciente* l, a lista  ser imprimida
 * Tem tipo de retorno void
 */
void imprime(struct paciente* l) {
    printf("Lista atualizada:\n");
    struct paciente* p = l;
    while (p != NULL) {
        printf("Num: %d ", p->order);
        switch (p->priority) {
            case VERMELHO:
	        printf("Prioridade: Vermelho\n");
	        break;
	    case AMARELO:
	        printf("Prioridade: Amarelo\n");
	        break;
	    case VERDE:
	        printf("Prioridade: Verde\n");
	        break;
	    default:
	        printf("Erro na leitura da prioridade.\n");
        }
	p = p->next;
    }
}

/* Funcao de retirada de no de lista encadeada, mas remove sempre o primeiro. Recebe como parametro
 * um struct paciente* l, a lista a ser manipulada
 * Retorna a lista atualizada, um struct paciente*
 */
struct paciente* atende(struct paciente* l, int imprimir) {
    if (l == NULL) {
	printf("Lista vazia.\n");
        return l; 
    }
    struct paciente* h = l;
    struct paciente* p = h->next;
    free(h);
    l = p;
    if (imprimir)
        imprime(l);
    return l;
}

/* Funcao de liberacao de memoria alocada de lista encadeada. Recebe como parametro
 * um struct paciente* l, a lista a ser liberada
 * Tem tipo de retorno void
 */ 
void libera_lista(struct paciente* l) {
    struct paciente* p = l;
    while (p != NULL)
        p = atende(p, 0);
    printf("Memoria liberada\n");		
}


