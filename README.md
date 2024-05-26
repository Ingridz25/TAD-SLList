
# TAD de Listas Simplesmente Encadeadas

Bem-vindo ao repositório do TAD de Listas Simplesmente Encadeadas! Este repositório contém a implementação de um Tipo Abstrato de Dados (TAD) para listas simplesmente encadeadas em C. Ele é ideal para estudos acadêmicos, projetos pessoais e aplicações que necessitem de uma estrutura de dados dinâmica e eficiente.

## Descrição

A lista simplesmente encadeada é uma estrutura de dados fundamental, onde cada elemento (nó) contém um valor e uma referência (ponteiro) para o próximo nó na sequência. Este TAD fornece uma implementação robusta e eficiente para manipular listas de forma simples e intuitiva.

## Funcionalidades

- **Inserção**: Adiciona novos elementos à lista, seja no início, fim ou em uma posição específica.
- **Remoção**: Remove elementos da lista, pelo valor ou por posição.
- **Busca**: Procura elementos na lista, retornando sua posição ou nó correspondente.
- **Exibição**: Imprime os elementos da lista para fácil visualização e debug.
- **Tamanho**: Retorna o número de elementos na lista.

## Estrutura do Repositório

- `src/`: Contém os arquivos fonte em C com a implementação do TAD.
  - `list.h`: Arquivo de cabeçalho com a definição da estrutura da lista e protótipos das funções.
  - `list.c`: Implementação das funções do TAD de lista simplesmente encadeada.
- `examples/`: Exemplos de uso da lista simplesmente encadeada.
  - `main.c`: Exemplo de programa que utiliza o TAD de lista simplesmente encadeada.
- `docs/`: Documentação do projeto.
  - `README.md`: Este arquivo, com informações sobre o projeto.
  
## Como Compilar

Para compilar os arquivos do TAD de lista simplesmente encadeada, você pode utilizar um compilador de C, como o `gcc`. Siga os passos abaixo:

```bash
gcc src/list.c examples/main.c -o list_example
