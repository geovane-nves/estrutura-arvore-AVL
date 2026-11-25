#ifndef AVL_H
#define AVL_H

typedef struct No {
    int value;
    int altura;

    struct No *left;
    struct No *right;
} No;

int maior(int a, int b);
int altura(No *no);
int fatorBalanceamento(No *no);

No *criarNo(int value);
No *inserir(No *raiz, int value);

No *rotacaoDireita(No *y);
No *rotacaoEsquerda(No *x);

void emOrdem(No *raiz);
void preOrdem(No *raiz);
void imprimirArvore(No *raiz, int nivel);

#endif
