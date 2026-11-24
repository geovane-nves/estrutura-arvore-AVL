#ifndef AVL_H
#define AVL_H

// Estrutura de um nó da árvore AVL
typedef struct No {
    int value;
    int altura;

    struct No *left;
    struct No *right;
} No;

// Funções auxiliares
int maior(int a, int b);
int altura(No *no);
int fatorBalanceamento(No *no);

// Criação e manipulação
No *criarNo(int value);
No *inserir(No *raiz, int value);

// Rotações
No *rotacaoDireita(No *y);
No *rotacaoEsquerda(No *x);

// Impressão
void emOrdem(No *raiz);
void preOrdem(No *raiz);
void imprimirArvore(No *raiz, int nivel);

#endif
