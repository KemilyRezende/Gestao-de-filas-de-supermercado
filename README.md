# Gestao-de-filas-de-supermercado
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

Este arquivo define a interface para um tipo de dado chamado `Array`, que é uma lista ligada de clientes identificados por CPF (um array de 11 caracteres).
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
- **Retorno:** Nenhum (ação).

**`void removeCliente(Array** a, const char cpf[11])`:**
- **Descrição:** Remove um cliente da lista, baseado no CPF.
- **Parâmetros:** Um ponteiro para a lista ligada de clientes (`a`) e o CPF do cliente a ser removido.
- **Retorno:** Nenhum (ação).

**`bool arrayContains(Array* a, const char cpf[11])`:**
- **Descrição:** Verifica se um determinado CPF está presente na lista.
- **Parâmetros:** Um ponteiro para a lista ligada de clientes (`a`) o CPF a ser verificado.
- **Retorno:** true se o CPF for encontrado, false caso contrário.

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
