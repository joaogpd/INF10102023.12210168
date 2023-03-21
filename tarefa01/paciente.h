#ifndef PACIENTE_H
#define PACIENTE_H

enum Priority {
    VERMELHO,
    AMARELO,
    VERDE
};

struct paciente {
    enum Priority priority;
    int order;
    struct paciente* next;
};

struct paciente* cria_lista(void);
struct paciente* cria_paciente(enum Priority r, int o);


#endif
