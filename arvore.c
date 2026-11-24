#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int value;
    int altura;

    struct No *rigth;
    struct No *left;
} No;

int maior(int a, int b){
    return (a > b) ? a : b;
}

int altura(No *no){
    if(no == NULL) { return 0; }
    return no->altura;
}

No *criarNo(int value){
    No *novo = malloc(sizeof(No));

    novo->value = value;
    novo->altura = 1;
    novo->rigth = NULL;
    novo->left = NULL;

    return novo;
}

int fatorBalanceamento(No *no){
    if (no == NULL) { return 0; }
    return (altura(no->left) - altura(no->rigth));
}

No *rotacaoDireita(No *y){
    No *x = y->rigth;
    No *T2 = x->rigth;

    x->rigth = y;
    y->left = T2;

    y->altura = maior(altura(y->left), altura(y->rigth));
    x->altura = maior(altura(x->left), altura(x->rigth));

    return x;
}

No *rotacaoEsquerda(No *x){
    No *y = x->rigth;
    No *T2 = y->left;

    y->left = x;
    x->rigth = T2;

    x->altura = maior(altura(x->left), altura(x->rigth));
    y->altura = maior(altura(y->left), altura(y->rigth));

    return y;
}

No* inserir(No *raiz, int value){

    if(raiz == NULL) { return criarNo(value); }

    if(value < raiz->value)
        raiz->left = inserir(raiz->left, value);
    else if (value > raiz->value)
        raiz->rigth = inserir(raiz->rigth, value);
    else 
        return raiz;

    raiz->altura = 1 + maior(altura(raiz->rigth), altura(raiz->left));
    int fatBal = fatorBalanceamento(raiz);

    // CASO 1 LL(lEFT LEFT)
    if (fatBal > 1 && value < raiz->left->value)
        return rotacaoDireita(raiz);
    
    // CASO 2 RR(RIGHT RIGTH)
    if (fatBal < -1 && value > raiz->rigth->value)
        return rotacaoEsquerda(raiz);

    // CASO 3 LR(LEFT RIGTH)
    if(fatBal > 1 && value > raiz->left->value){
        raiz->left = rotacaoEsquerda(raiz->left);
        return rotacaoDireita(raiz);
    }

    // CASO 4 RL (RIGTH LEFT)
    if (fatBal < -1 && value < raiz->rigth->value){
        raiz->rigth = rotacaoDireita(raiz->rigth);
        return rotacaoEsquerda(raiz);
    }
    return raiz;
}

void emOrdem(No *raiz){
    if (raiz != NULL){
        emOrdem(raiz->left);
        printf("%d", raiz->value);
        emOrdem(raiz->rigth);
    }
}

void preOrdem(No *raiz){
    if(raiz != NULL){
        printf("%d", raiz->value); 
        preOrdem(raiz->left);
        preOrdem(raiz->rigth);
    }
}

void imprimirArvore(No *raiz, int nivel){
    if(raiz == NULL)
        return;

    imprimirArvore(raiz->rigth, nivel + 1);

    for (int i = 0; i < nivel; i++)
        printf("    ");

    printf("%d\n", raiz->value);

    imprimirArvore(raiz->left, nivel + 1);
}


int main(){

    No *raiz = NULL;

    int values[] = {10, 20, 30, 40, 50, 60};
    // int values[] = {10, 30, 60, 20, 50, 80, 5, 2, 4};


    int tamanho = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < tamanho; i++){
        printf("Botando.... %d \n", values[i]);

        raiz = inserir(raiz, values[i]);

        printf("Arvore atual: \n");
        imprimirArvore(raiz, 0);

        printf("---------------\n");
    }
    return 0;
}