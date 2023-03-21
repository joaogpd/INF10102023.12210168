#include <stdio.h>
#include <stdlib.h>
#include "paciente.h"

// Retorna NULL para criar uma lista de struct paciente*
struct paciente* cria_lista(void) {
    return NULL;
}

// Cria uma nova instancia de um struct paciente*. O next tem valor padrao de NULL, 
// podendo ser alterado na implementacao. Retorna um struct paciente* e recebe um
// enum Priority e um int 
struct paciente* cria_paciente(enum Priority r, int o) {
    struct paciente* novo = (struct paciente*)malloc(sizeof(struct paciente));
    if (novo == NULL) return NULL;
    novo->priority = r;
    novo->order = o;
    novo->next = NULL;
    return novo;
}
