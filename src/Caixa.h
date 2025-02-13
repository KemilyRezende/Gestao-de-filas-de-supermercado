#include <stdbool.h> 
#ifndef CAIXA_H
#define CAIXA_H

#include "PriorityQueue.h"

typedef struct {
    int id;
    bool state;
    int count;
    priorityQueue* pq;
    void (*printFila)(priorityQueue*);
} Caixa;

void printFila(priorityQueue* pq);

#endif 