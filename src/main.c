#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "SLList.h"

#define TRUE 1
#define FALSE 0

int cmp(void *data, void *key);

typedef struct _aluno_ {
    char nome[30];
    int matricula;
    float nota;
} Aluno;

int main(void) {
    setlocale(LC_ALL, "Portuguese_Brazil");
    SLList *sll;
    int opcao = 0, listaCriada = 0, teste;

    do {
        printf("\n");
        printf("╔════════════════════════════════════════════════════════╗\n");
        printf("║                         MENU                           ║\n");
        printf("╠════════════════════════════════════════════════════════╣\n");
        printf("║  1. Criar lista                                        ║\n");
        printf("║  2. Inserir primeiro item da lista                     ║\n");
        printf("║  3. Inserir último item da lista                       ║\n");
        printf("║  4. Inserir um item depois de elemento especificado    ║\n");
        printf("║  5. Inserir um item antes de elemento especificado     ║\n");
        printf("║  6. Remover primeiro item da lista                     ║\n");
        printf("║  7. Remover último item da lista                       ║\n");
        printf("║  8. Remover item especificado da lista                 ║\n");
        printf("║  9. Mostrar todos os elementos da lista                ║\n");
        printf("║ 10. Verificar se a lista está vazia                    ║\n");
        printf("║ 11. Destruir a lista                                   ║\n");
        printf("║ 12. Sair                                               ║\n");
        printf("╚════════════════════════════════════════════════════════╝\n");
        printf(" Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (listaCriada == FALSE) {
                    sll = sllCreate();
                    if (sll != NULL) {
                        listaCriada = TRUE;
                    }
                } else {
                    printf("\nVocê já possui uma lista criada!");
                }
                break;

            case 2:
                if (listaCriada) {
                    Aluno *a = (Aluno *)malloc(sizeof(Aluno));
                    printf("\nAdicione item como primeiro elemento da lista: ");
                    printf("\nNome: ");
                    scanf("%s", a->nome);
                    printf("Matrícula: ");
                    scanf("%d", &a->matricula);
                    printf("Nota: ");
                    scanf("%f", &a->nota);

                    teste = sllInsertFirst(sll, (void *)a);
                    if (teste == TRUE) {
                        printf("\nElemento inserido!");
                    } else {
                        printf("\nNão foi possível inserir o elemento!");
                    }
                } else {
                    printf("\nATENÇÃO: Antes de utilizar as operações, você deve primeiramente criar uma lista!");
                }
                break;

            case 3:
                if (listaCriada) {
                    Aluno *a = (Aluno *)malloc(sizeof(Aluno));
                    printf("\nAdicione item como último elemento da lista: ");
                    printf("\nNome: ");
                    scanf("%s", a->nome);
                    printf("Matrícula: ");
                    scanf("%d", &a->matricula);
                    printf("Nota: ");
                    scanf("%f", &a->nota);

                    teste = sllInsertLast(sll, (void *)a);
                    if (teste == TRUE) {
                        printf("\nElemento inserido!");
                    } else {
                        printf("\nNão foi possível inserir o elemento!");
                    }
                } else {
                    printf("\nATENÇÃO: Antes de utilizar as operações, você deve primeiramente criar uma lista!");
                }
                break;

            case 4:
                if (listaCriada) {
                    Aluno *a = (Aluno *)malloc(sizeof(Aluno));
                    Aluno *spec = (Aluno *)malloc(sizeof(Aluno));
                    printf("\nAdicione item na lista: ");
                    printf("\nNome: ");
                    scanf("%s", a->nome);
                    printf("Matrícula: ");
                    scanf("%d", &a->matricula);
                    printf("Nota: ");
                    scanf("%f", &a->nota);
                    printf("\nApós qual matrícula você deseja inserir esse elemento: ");
                    scanf("%d", &spec->matricula);

                    teste = sllInsertAfterSpecQuery(sll, (void *)&spec->matricula, (void *)a, cmp);
                    if (teste == TRUE) {
                        printf("\nElemento inserido!");
                    } else {
                        printf("\nNão foi possível inserir o elemento!");
                    }
                } else {
                    printf("\nATENÇÃO: Antes de utilizar as operações, você deve primeiramente criar uma lista!");
                }
                break;

            case 5:
                if (listaCriada) {
                    Aluno *a = (Aluno *)malloc(sizeof(Aluno));
                    Aluno *spec = (Aluno *)malloc(sizeof(Aluno));
                    printf("\nAdicione item na lista: ");
                    printf("\nNome: ");
                    scanf("%s", a->nome);
                    printf("Matrícula: ");
                    scanf("%d", &a->matricula);
                    printf("Nota: ");
                    scanf("%f", &a->nota);
                    printf("\nAntes de qual matrícula você deseja inserir esse elemento: ");
                    scanf("%d", &spec->matricula);

                    teste = sllInsertBefSpec(sll, (void *)&spec->matricula, (void *)a, cmp);
                    if (teste == TRUE) {
                        printf("\nElemento inserido!");
                    } else {
                        printf("\nNão foi possível inserir o elemento!");
                    }
                } else {
                    printf("\nATENÇÃO: Antes de utilizar as operações, você deve primeiramente criar uma lista!");
                }
                break;

            case 6:
                if (listaCriada) {
                    Aluno *a;
                    a = (Aluno *)sllRemoveFirst(sll);
                    if (a != NULL) {
                        printf("\nElemento %s com matrícula %d foi retirado da lista!", a->nome, a->matricula);
                        free(a);
                    } else {
                        printf("\nNão foi possível retirar o elemento da lista!");
                    }
                } else {
                    printf("\nATENÇÃO: Antes de utilizar as operações, você deve primeiramente criar uma lista!");
                }
                break;

            case 7:
                if (listaCriada) {
                    Aluno *a;
                    a = (Aluno *)sllRemoveLast(sll);
                    if (a != NULL) {
                        printf("\nElemento %s com matrícula %d foi retirado da lista!", a->nome, a->matricula);
                        free(a);
                    } else {
                        printf("\nNão foi possível retirar o elemento da lista!");
                    }
                } else {
                    printf("\nATENÇÃO: Antes de utilizar as operações, você deve primeiramente criar uma lista!");
                }
                break;

            case 8:
                if (listaCriada) {
                    Aluno *spec = (Aluno *)malloc(sizeof(Aluno));
                    Aluno *a;
                    printf("\nDigite a matrícula do elemento que você deseja retirar: ");
                    scanf("%d", &spec->matricula);
                    a = (Aluno *)sllRemoveSpec(sll, (void *)&spec->matricula, cmp);

                    if (a != NULL) {
                        printf("\nElemento %s com matrícula %d foi retirado da lista!", a->nome, a->matricula);
                        free(a);
                    } else {
                        printf("\nNão foi possível retirar o elemento da lista!");
                    }
                    free(spec);
                } else {
                    printf("\nATENÇÃO: Antes de utilizar as operações, você deve primeiramente criar uma lista!");
                }
                break;

            case 9:
                if (listaCriada) {
                    if (sll->first != NULL) {
                        int aux = 0;
                        Aluno *a;
                        SLNode *node = sll->first;
                        while (node != NULL) {
                            aux++;
                            a = (Aluno *)node->data;
                            printf("\nElemento %d: Nome: %s, Matrícula: %d, Nota: %.2f", aux, a->nome, a->matricula, a->nota);
                            node = node->next;
                        }
                    } else {
                        printf("\nNão há elementos na lista!");
                    }
                } else {
                    printf("\nATENÇÃO: Antes de utilizar as operações, você deve primeiramente criar uma lista!");
                }
                break;

            case 10:
                if (listaCriada) {
                    teste = sllIsEmpty(sll);
                    if (teste == TRUE) {
                        printf("\nLista vazia!");
                    } else {
                        printf("\nA lista não está vazia!");
                    }
                } else {
                    printf("\nATENÇÃO: Antes de utilizar as operações, você deve primeiramente criar uma lista!");
                }
                break;

            case 11:
                if (listaCriada) {
                    teste = sllDestroy(sll);
                    if (teste == TRUE) {
                        printf("\nLista destruída!");
                        listaCriada = FALSE;
                    } else {
                        printf("\nNão foi possível destruir a lista!");
                    }
                } else {
                    printf("\nATENÇÃO: Antes de utilizar as operações, você deve primeiramente criar uma lista!");
                }
                break;

            case 12:
                printf("\nSaindo...\n");
                break;

            default:
                printf("\nOpção inválida!");
                break;
        }
    } while (opcao != 12);

    return 0;
}

int cmp(void *data, void *key) {
    Aluno *a = (Aluno *)data;
    int *k = (int *)key;
    if (a->matricula == *k) {
        return TRUE;
    } else {
        return FALSE;
    }
}
