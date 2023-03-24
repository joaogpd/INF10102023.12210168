#ifndef PACIENTE_H
#define PACIENTE_H

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

#endif
