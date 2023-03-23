#include <stdio.h>
#include <stdlib.h>
#include "operacoes.h"
#include "paciente.h"

struct paciente* desiste_ou_atende(struct paciente* l, int input, int desiste) {
    struct paciente* h = NULL;
    struct paciente* p = l;
    
    while (p != NULL && (des ? p->order : p->priority)) {
        h = p;
        p = p->next;
    }
    	
    if (p == NULL)
	return l;
    h->next = p->next;
    free(p);
    return l;
}


// Retorna NULL para criar uma lista de struct paciente*
struct paciente* cria_lista(void) {
    return NULL;
}

// Insere um paciente que chegou na lista em ordem de prioridade e de chegada
// Recebe um enum e um int como parametros, retornando um struct paciente*
struct paciente* chegada(struct paciente* l, enum Priority r, int o) {
    struct paciente* novo = cria_paciente(r, o);
    if (novo == NULL) {
        fprintf(stderr, "Erro ao alocar memoria");
	return NULL;
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

// Imprime todos os nos da lista encadeada de pacientes, tem tipo de retorno void
// e recebe um struct paciente*
void imprime(struct paciente* l) {
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

// Permite que um usuario seja atenendido, sendo retirado do inicio
// da lista (em ordem de prioridade). Recebe e retorna um struct paciente*,
// uma copia atualizada da lista
struct paciente* atende(struct paciente* l) {
    if (l == NULL) {
	printf("Lista vazia.\n");
        return l; 
    }
    struct paciente* h = l;
    struct paciente* p = h->next;
    free(h);
    l = p;
    imprime(l);
    return l;
}

// Libera a memoria alocada dos nos da lista. Tipo de retorno void, recebe
// uma lista encadeada de struct paciente*
void libera_lista(struct paciente* l) {
    struct paciente* p = l;
    while (p != NULL)
        p = atende(p);		
}


