#include "PriorityQueue.h"
#include <stdlib.h>
#include <stdio.h>

void insert(priorityQueue* pq, Cliente c) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Erro ao alocar memória.\n");
        return;
    }

    newNode->c = c;
    newNode->next = NULL;

    if (pq->head == NULL || pq->head->c.pr > c.pr) {
        newNode->next = pq->head;
        pq->head = newNode;
    } else {
        Node* aux = pq->head;
        while (aux->next != NULL && aux->next->c.pr <= c.pr) {
            aux = aux->next;
        }
        newNode->next = aux->next;
        aux->next = newNode;
    }
}

/* 
Cliente removeClient(priorityQueue* pq) {
    if (pq->head == NULL) {
        printf("Caixa vazio\n");
        Cliente empty = {"", "", 0, 0};
        return empty;
    }
    Node* aux = pq->head;
    Cliente removed = aux->c;
    pq->head = pq->head->next;
    free(aux);
    return removed;
} */

Cliente* removeClient(priorityQueue* pq) {
    if (pq->head == NULL) {
        printf("Caixa vazio\n");
        return NULL;
    }
    Node* aux = pq->head;
    Cliente* removed = (Cliente*)malloc(sizeof(Cliente));
    if (!removed) {
        printf("Erro ao alocar memória\n");
        return NULL;
    }
    *removed = aux->c;
    pq->head = pq->head->next;
    free(aux);
    return removed;
}
