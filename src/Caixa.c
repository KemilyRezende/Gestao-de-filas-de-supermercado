#include "Caixa.h"
#include <stdio.h>

void printFila(priorityQueue* pq) {
    Node* aux = pq->head;
    printf("Lista de Clientes\n______________________________\n");
    while (aux) {
        printf("Cliente: %s\n", aux->c.nome);
        printf("CPF: %s\n", aux->c.cpf);
        printf("Quantidade de itens: %d\n", aux->c.qtde);
        printf("Prioridade: %s\n", aux->c.pr == 1 ? "Alta" : (aux->c.pr == 2 ? "Média" : "Baixa"));
        printf("------------------------------\n");
        aux = aux->next;
    }
}
