# Gestao-de-filas-de-supermercado
## Descrição:
Este projeto implementa um sistema de gerenciamento de filas em um supermercado. O objetivo é oferecer um atendimento eficiente e justo para os clientes. O sistema gerencia múltiplos caixas e distribui os clientes conforme suas prioridades, utilizando estruturas de dados como listas encadeadas e filas de prioridade.

## Funcionalidades:

1. **Cadastro de Clientes:** Adiciona um cliente à fila de um caixa específico, considerando sua prioridade.
2. **Atendimento de Clientes:** Remove o cliente de maior prioridade do caixa especificado.
3. **Abertura e Fechamento de Caixas:** Permite abrir e fechar caixas conforme necessário, realocando clientes automaticamente.
4. **Impressão de Listas:** Exibe a fila de espera de cada caixa, organizada por prioridade.
5. **Status dos Caixas:** Mostra quais caixas estão abertos ou fechados e quantos clientes estão aguardando em cada um.

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
