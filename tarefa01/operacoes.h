#ifndef OPERACOES_H
#define OPERACOES_H
#include "paciente.h"

// tipo de dados paciente
struct paciente;
// tipo enum Priority
enum Priority;

struct paciente* desiste_ou_transfere(struct paciente* l, int input, int desiste, int* priority);
// retorna NULL para criar uma lista encadeada
struct paciente* cria_lista(void);
// insere um novo paciente na lista encadeada (mantem ordenacao)
struct paciente* chegada(struct paciente* l, enum Priority r, int o);
// imprime todos os elementos da lista encadeada
void imprime(struct paciente* l);
// remove o primeiro elemento da lista encadeada 
struct paciente* atende(struct paciente* l);
// libera a memoria alocada da lista encadeada
void libera_lista(struct paciente* l);

#endif
