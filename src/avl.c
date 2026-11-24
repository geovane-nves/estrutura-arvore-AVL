#include <stdio.h>
#include <stdlib.h>
#include "../include/avl.h"

// Retorna o maior entre dois valores
int maior(int a, int b) {
    return (a > b) ? a : b;
}

// Retorna a altura de um nó
int altura(No *no) {
    if (no == NULL)
        return 0;

    return no->altura;
}

// Calcula o fator de balanceamento
int fatorBalanceamento(No *no) {
    if (no == NULL)
        return 0;

    return altura(no->left) - altura(no->right);
}

// Cria um novo nó
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

// Rotação simples à direita
No *rotacaoDireita(No *y) {
    No *x = y->left;
    No *T2 = x->right;

    x->right = y;
    y->left = T2;

    // Atualiza as alturas
    y->altura = 1 + maior(altura(y->left), altura(y->right));
    x->altura = 1 + maior(altura(x->left), altura(x->right));

    return x;
}

// Rotação simples à esquerda
No *rotacaoEsquerda(No *x) {
    No *y = x->right;
    No *T2 = y->left;

    y->left = x;
    x->right = T2;

    // Atualiza as alturas
    x->altura = 1 + maior(altura(x->left), altura(x->right));
    y->altura = 1 + maior(altura(y->left), altura(y->right));

    return y;
}

// Insere um valor e realiza o balanceamento da árvore
No *inserir(No *raiz, int value) {

    // Inserção normal de uma árvore binária de busca
    if (raiz == NULL)
        return criarNo(value);

    if (value < raiz->value)
        raiz->left = inserir(raiz->left, value);

    else if (value > raiz->value)
        raiz->right = inserir(raiz->right, value);

    else
        return raiz;

    // Atualiza a altura do nó atual
    raiz->altura = 1 + maior(
        altura(raiz->left),
        altura(raiz->right)
    );

    // Calcula o fator de balanceamento
    int fatBal = fatorBalanceamento(raiz);

    // CASO LL: rotação simples à direita
    if (fatBal > 1 && value < raiz->left->value)
        return rotacaoDireita(raiz);

    // CASO RR: rotação simples à esquerda
    if (fatBal < -1 && value > raiz->right->value)
        return rotacaoEsquerda(raiz);

    // CASO LR: rotação à esquerda e depois à direita
    if (fatBal > 1 && value > raiz->left->value) {
        raiz->left = rotacaoEsquerda(raiz->left);
        return rotacaoDireita(raiz);
    }

    // CASO RL: rotação à direita e depois à esquerda
    if (fatBal < -1 && value < raiz->right->value) {
        raiz->right = rotacaoDireita(raiz->right);
        return rotacaoEsquerda(raiz);
    }

    return raiz;
}

// Percurso em ordem: esquerda, raiz, direita
void emOrdem(No *raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->left);
        printf("%d ", raiz->value);
        emOrdem(raiz->right);
    }
}

// Percurso pré-ordem: raiz, esquerda, direita
void preOrdem(No *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->value);
        preOrdem(raiz->left);
        preOrdem(raiz->right);
    }
}

// Exibe a árvore deitada no terminal
void imprimirArvore(No *raiz, int nivel) {
    if (raiz == NULL)
        return;

    imprimirArvore(raiz->right, nivel + 1);

    for (int i = 0; i < nivel; i++)
        printf("    ");

    printf("%d\n", raiz->value);

    imprimirArvore(raiz->left, nivel + 1);
}