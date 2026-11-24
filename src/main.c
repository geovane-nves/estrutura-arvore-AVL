#include <stdio.h>
#include "../include/avl.h"

int main() {

    No *raiz = NULL;

    int values[] = {10, 20, 30, 40, 50, 60};

    int tamanho = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < tamanho; i++) {

        printf("Inserindo: %d\n", values[i]);

        raiz = inserir(raiz, values[i]);

        printf("Arvore atual:\n");
        imprimirArvore(raiz, 0);

        printf("-------------------\n");
    }

    printf("\nPercurso em ordem: ");
    emOrdem(raiz);

    printf("\nPercurso pre-ordem: ");
    preOrdem(raiz);

    printf("\n");

    return 0;
}