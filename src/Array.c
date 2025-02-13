#include "Array.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int size(Array* a) {
    int count = 0;
    Array* cont = a;
    while (cont) {
        cont = cont->prox;
        count++;
    }
    return count;
}

void addCliente(Array** a, const char cpf[11]) {
    Array* novo = (Array*)malloc(sizeof(Array)); 
    if (!novo) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    strcpy(novo->cpf, cpf);
    novo->prox = NULL;

    if (*a == NULL) {
        *a = novo; 
    } else {
        Array* temp = *a;
        while (temp->prox) {
            temp = temp->prox;
        }
        temp->prox = novo; 
    }
}

void removeCliente(Array** a, const char cpf[11]) {
    Array* temp = *a;
    Array* anterior = NULL;

    while (temp) {
        if (strcmp(temp->cpf, cpf) == 0) { 
            if (anterior == NULL) {
                *a = temp->prox;
            } else {
                anterior->prox = temp->prox;
            }
            free(temp);
            return;
        }
        anterior = temp;
        temp = temp->prox;
    }
    printf("CPF não encontrado.\n");
}

bool arrayContains(Array* a, const char cpf[11]) {
    while (a) {
        if (strcmp(a->cpf, cpf) == 0) {
            return true;
        }
        a = a->prox;
    }
    return false;
}