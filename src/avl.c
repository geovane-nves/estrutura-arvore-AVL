#include <stdio.h>
#include <stdlib.h>
#include "../include/avl.h"

int maior(int a, int b) {
    return (a > b) ? a : b;
}

int altura(No *no) {
    if (no == NULL)
        return 0;

    return no->altura;
}

int fatorBalanceamento(No *no) {
    if (no == NULL)
        return 0;

    return altura(no->left) - altura(no->right);
}

No *criarNo(int value) {
    No *novo = malloc(sizeof(No));

    if (novo == NULL)
        return NULL;

    novo->value = value;
    novo->altura = 1;
    novo->left = NULL;
    novo->right = NULL;

    return novo;
}

No *rotacaoDireita(No *y) {
    No *x = y->left;
    No *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->altura = 1 + maior(altura(y->left), altura(y->right));
    x->altura = 1 + maior(altura(x->left), altura(x->right));

    return x;
}

No *rotacaoEsquerda(No *x) {
    No *y = x->right;
    No *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->altura = 1 + maior(altura(x->left), altura(x->right));
    y->altura = 1 + maior(altura(y->left), altura(y->right));

    return y;
}

No *inserir(No *raiz, int value) {

    if (raiz == NULL)
        return criarNo(value);

    if (value < raiz->value)
        raiz->left = inserir(raiz->left, value);

    else if (value > raiz->value)
        raiz->right = inserir(raiz->right, value);

    else
        return raiz;

    raiz->altura = 1 + maior(
        altura(raiz->left),
        altura(raiz->right)
    );

    int fatBal = fatorBalanceamento(raiz);

    if (fatBal > 1 && value < raiz->left->value)
        return rotacaoDireita(raiz);

    if (fatBal < -1 && value > raiz->right->value)
        return rotacaoEsquerda(raiz);

    if (fatBal > 1 && value > raiz->left->value) {
        raiz->left = rotacaoEsquerda(raiz->left);
        return rotacaoDireita(raiz);
    }

    if (fatBal < -1 && value < raiz->right->value) {
        raiz->right = rotacaoDireita(raiz->right);
        return rotacaoEsquerda(raiz);
    }

    return raiz;
}

void emOrdem(No *raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->left);
        printf("%d ", raiz->value);
        emOrdem(raiz->right);
    }
}

void preOrdem(No *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->value);
        preOrdem(raiz->left);
        preOrdem(raiz->right);
    }
}

void imprimirArvore(No *raiz, int nivel) {
    if (raiz == NULL)
        return;

    imprimirArvore(raiz->right, nivel + 1);

    for (int i = 0; i < nivel; i++)
        printf("    ");

    printf("%d\n", raiz->value);

    imprimirArvore(raiz->left, nivel + 1);
}