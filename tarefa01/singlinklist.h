// 2210168 - Joao Gabriel Peixoto Drumond Lopes
#ifndef SINGLINKLIST_H
#define SINGLINKLIST_H

// tipo enum Priority, define as prioridades de atendimento
enum Priority {
    VERMELHO,
    AMARELO,
    VERDE
};
// tipo estruturado paciente
struct paciente {
    enum Priority priority;
    int order;
    struct paciente* next;
};

// cria e aloca uma instancia do tipo estruturado paciente e o retorna
struct paciente* cria_paciente(enum Priority r, int o);
// retira um paciente da lista que desistiu (pelo numero de chegada) ou que foi transferido
// (pela ordem de prioridade). A distincao ocorre pela flag desiste. Priority guarda a
// referência da prioridade do elemento removido
struct paciente* desiste_ou_transfere(struct paciente* l, int input, int desiste, int* priority);
// retorna NULL para criar uma lista encadeada
struct paciente* cria_lista(void);
// insere um novo paciente na lista encadeada (mantem ordenacao)
struct paciente* chegada(struct paciente* l, enum Priority r, int o);
// imprime todos os elementos da lista encadeada
void imprime(struct paciente* l);
// remove o primeiro elemento da lista encadeada. Imprime ou não o resultado, de acordo com 
// a flag imprimir 
struct paciente* atende(struct paciente* l, int imprimir);
// libera a memoria alocada da lista encadeada
void libera_lista(struct paciente* l);

#endif
