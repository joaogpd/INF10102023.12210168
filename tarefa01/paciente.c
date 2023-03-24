#include <stdio.h>
#include <stdlib.h>
#include "paciente.h"

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
