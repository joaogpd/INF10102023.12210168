#ifndef OPERACOES_H
#define OPERACOES_H
#include "paciente.h"

struct paciente;
enum Priority;

struct paciente* cria_lista(void);
struct paciente* chegada(struct paciente* l, enum Priority r, int o);
void imprime(struct paciente* l);
struct paciente* atende(struct paciente* l);
void libera_lista(struct paciente* l);

#endif
