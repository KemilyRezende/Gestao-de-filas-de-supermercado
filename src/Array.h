#ifndef ARRAY_H
#define ARRAY_H

#include <stdbool.h>

typedef struct Array {
    char cpf[11];
    struct Array* prox;
} Array;

int size(Array* a);
void addCliente(Array** a, const char cpf[11]);
void removeCliente(Array** a, const char cpf[11]);
bool arrayContains(Array* a, const char cpf[11]);

#endif
