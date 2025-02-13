#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include "Cliente.h"
#include "Caixa.h"
#include "Array.h"

int getSmallestQueueIndex(Caixa c[], int qtdCaixa){
    int minCount = INT_MAX;
    int minIndex = -1;

    for (int i = 0; i < qtdCaixa; i++) {
        if (c[i].state && c[i].count < minCount) {
            minCount = c[i].count;
            minIndex = i;
        }
    }
    return minIndex;
}

/* void realoc(int cx, Caixa c[], int qtdCaixa){
    Node* aux = c[cx-1].pq->head;
    while(aux){
        int a = getSmallestQueueIndex(c, qtdCaixa);
        c[cx-1].count--;
        Cliente x = c[cx-1].pq->removeClient(c[cx-1].pq);
        c[a].count++;
        c[a].pq->insert(c[a].pq, aux->c);
        printf("Cliente %s realocado do caixa %d para o caixa %d", x.nome, cx, a+1);
        aux = aux->next;
    }
} */
void realoc(int cx, Caixa c[], int qtdCaixa) {
    while (c[cx-1].pq->head) {  // Enquanto houver clientes no caixa fechado
        int a = getSmallestQueueIndex(c, qtdCaixa);
        c[cx-1].count--;
        Cliente* x = c[cx-1].pq->removeClient(c[cx-1].pq);
        if (x) {
            c[a].count++;
            c[a].pq->insert(c[a].pq, *x);
            printf("Cliente %s realocado do caixa %d para o caixa %d\n", x->nome, cx, a+1);
            free(x);  // Liberar memória do cliente realocado
        }
    }
}


int main(){
    
    int qtdCaixa;
    int open;
    Array *a = NULL;
    printf("Defina a quantidade de caixas:\n");
    scanf("%d", &qtdCaixa);

    Caixa caixas[qtdCaixa];

    for (int i = 0; i < qtdCaixa; i++){
        Caixa c;
        c.id = i+1;
        c.state = true;
        c.pq = (priorityQueue*)malloc(sizeof(priorityQueue)); 
        c.pq->head = NULL;
        c.count = 0;
        c.pq->insert = insert; 
        c.pq->removeClient = removeClient;
        c.printFila = printFila;
        caixas[i] = c;
    }

    open = qtdCaixa;

    int op = 0;
    int cx = 0;

    do {
        printf("Operacoes:\n    1. Cadastrar clientes\n    2. Atender um cliente\n    3. Abrir ou fechar caixa\n    4. Imprimir a lista de clientes em espera\n    5. Imprimir os status dos caixas\n    6. Sair\n");
        scanf("%d", &op);
        Cliente c;
        switch (op)
        {
        case 1:
            printf("Digite o nome do cliente:\n");
            scanf(" %[^\n]", c.nome);
            printf("Digite o cpf do cliente (apenas números):\n");
            scanf("%s", c.cpf);
            if (arrayContains(a, c.cpf)){
                printf("Este cliente já está aguardando atendimento.");
                break;
            }
            printf("Qual é a prioridade do cliente?\n1 - Alta\n2 - Media\n3 - Baixa\n");
            scanf("%d", &c.pr);
            printf("Quantidade de itens:\n");
            scanf("%d", &c.qtde);
            bool errorCx = true;
            do{
                printf("ID do caixa:\n");
                scanf("%d", &cx);
                if (cx < 1 || cx > qtdCaixa){
                    printf("Caixa não cadastrado! Insira um ID válido:\n");
                }
                else if(!caixas[cx-1].state){
                    printf("Caixa fechado! Insira um ID válido:\n");
                }
                else {
                    errorCx = false;
                    caixas[cx-1].pq->insert(caixas[cx-1].pq, c);
                    caixas[cx-1].count++;
                    addCliente(&a, c.cpf);
                }
            } while(errorCx);
            break;
        
        case 2:/* 
            printf("ID  do caixa a atender:\n");
            scanf("%d", &cx);
            Cliente x = caixas[cx-1].pq->removeClient(caixas[cx].pq);
            caixas[cx-1].count--;
            removeCliente(&a, x.cpf);
            break; */
            printf("ID do caixa a atender:\n");
            scanf("%d", &cx);
            Cliente* x = caixas[cx-1].pq->removeClient(caixas[cx-1].pq);
            if (x) {  // Verifica se a remoção foi bem-sucedida
                caixas[cx-1].count--;
                removeCliente(&a, x->cpf);
            free(x);  // Liberar memória do cliente removido
            }
            break;


        case 3:
            printf("ID do caixa abrir/fechar:\n");
            scanf("%d", &cx);
            if (cx < 1 || cx > qtdCaixa) printf("Caixa inexistente\n");
            else {
                if(!caixas[cx-1].state){
                    caixas[cx-1].state = true;
                    printf("Caixa aberto com sucesso.\n");
                    open++;
                }
                else{
                    if(open == 1){
                        printf("Único caixa aberto. Não foi possível fechar.");
                    }
                    else{
                        open--;
                        if(caixas[cx-1].count == 0){
                            caixas[cx-1].state = false;
                            printf("Caixa fechado com sucesso.\n");
                        }
                        else{
                            caixas[cx-1].state = false;
                            realoc(cx, caixas, qtdCaixa);
                            printf("Caixa fechado com sucesso.\n");
                        }
                    }
                }
            }
            
            break;

        case 4:
            printf("ID do caixa a imprimir lista de clientes:\n");
            scanf("%d", &cx);
            if (cx < 1 || cx > qtdCaixa) printf("Caixa inexistente\n");
            else {
                caixas[cx-1].printFila(caixas[cx-1].pq);
            }
            break;

        case 5:
            printf("Lista de caixas: \n");
            for(int i = 0; i < qtdCaixa; i++){
                if(caixas[i].state) printf("Caixa %d: aberto.\n", i+1);
                else printf("Caixa %d: fechado.\n", i+1);
            }
            break;

        case 6:
            printf("Encerrando programa\n");
            break;
        
        default:
            printf("Operacao invalida.\n");
            break;
        }
    } while (op != 6);

    return 0;
}