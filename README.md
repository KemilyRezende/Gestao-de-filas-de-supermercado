# Gestao de filas de supermercado

## Descrição:
Este projeto implementa um sistema de gerenciamento de filas em um supermercado. O objetivo é oferecer um atendimento eficiente e justo para os clientes. O sistema gerencia múltiplos caixas e distribui os clientes conforme suas prioridades, utilizando estruturas de dados como listas encadeadas e filas de prioridade.

## Funcionalidades:

1. **Cadastro de Clientes:** Adiciona um cliente à fila de um caixa específico, considerando sua prioridade.
2. **Atendimento de Clientes:** Remove o cliente de maior prioridade do caixa especificado.
3. **Abertura e Fechamento de Caixas:** Permite abrir e fechar caixas conforme necessário, realocando clientes automaticamente.
4. **Impressão de Listas:** Exibe a fila de espera de cada caixa, organizada por prioridade.
5. **Status dos Caixas:** Mostra quais caixas estão abertos ou fechados e quantos clientes estão aguardando em cada um.

## Estrutura de arquivos

### Array.h e Array.c

Estes arquivos definem a interface para um tipo de dado chamado `Array`, que é uma lista ligada de clientes identificados por CPF (um array de 11 caracteres).
Cada `Array` representa um nó de uma lista encadeada utilizada para controle de cadastro, através dela não é possível cadastrar um cliente que já está agurdando na fila de um dos caixas. Cada nó contem:
- `cpf[11]`: Um array de caracteres que armazena o CPF do cliente.
- `prox`: Ponteiro para o próximo nó da lista (ou `NULL` se for o último nó).

#### Funções:
    
**`int size(Array* a)`:**
- **Descrição:** Retorna o número de elementos na lista ligada (quantos CPFs estão armazenados).
- **Parâmetros:** Um ponteiro para a lista ligada de clientes.
- **Retorno:** Um inteiro que representa o tamanho da lista.

**`void addCliente(Array** a, const char cpf[11])`:**
- **Descrição:** Adiciona um novo cliente (CPF) à lista.
- **Parâmetros:** Um ponteiro para a lista ligada de clientes (`a`) e o CPF do cliente a ser adicionado.
- **Retorno:** Nenhum.

**`void removeCliente(Array** a, const char cpf[11])`:**
- **Descrição:** Remove um cliente da lista, baseado no CPF.
- **Parâmetros:** Um ponteiro para a lista ligada de clientes (`a`) e o CPF do cliente a ser removido.
- **Retorno:** Nenhum.

**`bool arrayContains(Array* a, const char cpf[11])`:**
- **Descrição:** Verifica se um determinado CPF está presente na lista.
- **Parâmetros:** Um ponteiro para a lista ligada de clientes (`a`) o CPF a ser verificado.
- **Retorno:** true se o CPF for encontrado, false caso contrário.

### Cliente.h

Este arquivo define a estrutura Cliente, que armazena informações sobre um cliente, como nome, CPF, prioridade e quantidade de algum item (pode ser um produto ou recurso, dependendo do contexto do programa). Contém:
- `nome[100]`: Um array de caracteres que armazena o nome do cliente (com limite de 100 caracteres).
- `cpf[11]`: Um array de caracteres que armazena o CPF do cliente (é esperado receber apenas os números do CPF).
- `pr`: Um inteiro que representa a prioridade do cliente. (1 - alta, 2 - média, 3 - baixa).
- `qtde`: Um inteiro que representa a quantidade de algo relacionado ao cliente.

### priorityQueue.h e priorityQueue.c

Estes arquivos definem a estrutura de dados e as funções para uma fila de prioridade, onde cada elemento da fila é um cliente (Cliente). A fila organiza os clientes com base em sua prioridade, com o cliente de maior prioridade sempre na frente da fila.

#### Estruturas de dados:

**`Node`:** Tipo de dado que representa um nó em uma lista ligada. Cada nó contém:
- `c`: Um objeto do tipo `Cliente`, representando as informações do cliente.
- `next`: Ponteiro para o próximo nó da lista (ou `NULL` se for o último nó).
  
**`priorityQueue`:** Tipo de dado que representa a fila de prioridade. Contém:
- `head`: Ponteiro para o primeiro nó da lista (o cliente com maior prioridade).
- `insert`: Função que insere um cliente na fila de prioridade.
- `removeClient`: Função que remove e retorna o cliente com a maior prioridade.

#### Funções

**`void insert(priorityQueue* pq, Cliente c)`:**
- **Descrição:** Insere um cliente na fila de prioridade. A fila é organizada de forma que o cliente com maior prioridade sempre esteja no começo.
- **Parâmetros:** Ponteiro para a fila de prioridade (`pq`) e cliente a ser inserido na fila (`c`).
- **Retorno:** Nenhum.

**`Cliente* removeClient(priorityQueue* pq)`:**
- **Descrição:** Remove e retorna o cliente com a maior prioridade da fila.
- **Parâmetros:** Ponteiro para a fila de prioridade (`pq`).
- **Retorno:** Um ponteiro para o cliente removido da fila. Se a fila estiver vazia, retorna `NULL`.

### Caixa.h e Caixa.c

Estes arquivos definem a estrutura de um caixa e suas funções associadas. Um caixa representa um ponto de atendimento no supermercado, onde os clientes são atendidos em uma fila de prioridade. Cada Caixa contém:
- `id`: Número de identificação do caixa.
- `state`: Indica se o caixa está aberto (true) ou fechado (false).
- `count`: Número de clientes aguardando na fila do caixa.
- `pq`: Ponteiro para a fila de prioridade associada ao caixa.
- `printFila`: Ponteiro para função que imprime a lista de clientes em esper

#### Funções

**`void printFila(priorityQueue* pq)`:**
- **Descrição:** Exibe a lista de clientes em espera em um caixa, ordenada por prioridade.
- **Parâmetros:** Ponteiro para a fila de prioridade (`pq`).
- **Retorno:** Nenhum.

### main.c

O arquivo `main.c` é o ponto de entrada do programa. Ele contém a inicialização do sistema, gerenciamento dos caixas e interação com o usuário por meio de um menu de opções.

#### Funções

**`int getSmallestQueueIndex(Caixa c[], int qtdCaixa)`:**
- **Descrição:** Retorna o índice do caixa com a menor quantidade de clientes.
- **Parâmetros:** `Array` de caixas (`c[]`) e quantidade de caixas (`qtdCaixa`).
- **Retorno:** Índice do caixa com menos clientes.

**`void realoc(int cx, Caixa c[], int qtdCaixa)`:**
- **Descrição:** Realoca clientes de um caixa fechado para o caixa com menos clientes.
- **Parâmetros:** ID do caixa a ser fechado (´cx´), array de caixas (´c[]´), quantidade de caixas (´qtdCaixa´).
- **Retorno:** Nenhum.

**`int main()`:**
- **Descrição:** Função principal do programa. Gerencia a interação com o usuário e controla o fluxo do sistema.
- **Parâmetros:** Nenhum.
- **Retorno:** 0 em caso de execução bem-sucedida.

## Bibliotecas Utilizadas:

- `<stdlib.h>`: Biblioteca padrão do C que contém funções para gerenciamento de memória, conversão de tipos, geração de números aleatórios e controle do programa. Aloca e libera memória para a fila de prioridade (`malloc()`, `free()`).
- `<stdio.h>`: Responsável pela entrada e saída de dados, como exibição de texto na tela e leitura do teclado (`scanf()`, `printf()`).
- `<string.h>`: Contém funções para manipulação de strings, como cópia, concatenação e comparação. Compara CPFs e copia string ao cadastrar clientes (`strcmp()`, `strcpy()`).
- `<stdbool.h>`: Define os valores true e false para o tipo bool.
- `<limits.h>`: Fornece os valores mínimos e máximos que variáveis de tipos primitivos podem armazenar. (`INT_MAX` na função `getSmallestQueueIndex()`)

## Compilar e executar
### Como compilar
Execute o seguinte comando no terminal:
```
make
```
### Como rodar
Execute o seguinte comando no terminal:
```
make run
```

## Observações

- Durante a execução ao solicitar o ID do caixa é esperado a numeração "natural" para o usuário (não utilizar o index do vetor, tal tratamento é feito no programa).
