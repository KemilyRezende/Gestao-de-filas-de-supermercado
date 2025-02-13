#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "Cliente.h"

typedef struct Node {
    Cliente c;
    struct Node* next;
} Node;


typedef struct priorityQueue{
    Node* head;
    void (*insert)(struct priorityQueue*, Cliente);
    Cliente* (*removeClient)(struct priorityQueue*);
} priorityQueue;

void insert(priorityQueue* pq, Cliente c);
Cliente* removeClient(priorityQueue* pq);

#endif