#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int altura;
    int quantidade;
    struct No *esq;
    struct No *dir;
} No;

No* criarNo(int h) {
    No* novo = (No*)malloc(sizeof(No));
    novo->altura = h;
    novo->quantidade = 1;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

No* inserir(No* raiz, int h) {
    if (raiz == NULL) {
        return criarNo(h);
    }

    if (h == raiz->altura) {
        raiz->quantidade++;
        return raiz;
    }

    if (h < raiz->altura) {
        raiz->esq = inserir(raiz->esq, h);
    } else {
        raiz->dir = inserir(raiz->dir, h);
    }

    return raiz;
}

int primeiro_impresso = 1;

void imprimirEmOrdem(No* raiz) {
    if (raiz != NULL) {
        imprimirEmOrdem(raiz->esq);

        for (int i = 0; i < raiz->quantidade; i++) {
            if (!primeiro_impresso) {
                printf(" ");
            }
            printf("%d", raiz->altura);
            primeiro_impresso = 0;
        }

        imprimirEmOrdem(raiz->dir);
    }
}

void liberarArvore(No* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esq);
        liberarArvore(raiz->dir);
        free(raiz);
    }
}

void scan_int(int *n) {
    int ch = getchar();
    *n = 0;
    while (ch < '0' || ch > '9') {
        if (ch == EOF) return;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        *n = (*n * 10) + (ch - '0');
        ch = getchar();
    }
}

int main() {
    int NC;
    if (scanf("%d", &NC) != 1) return 0;

    while (NC--) {
        int N;
        scan_int(&N);

        No* raiz = NULL;
        int altura;

        for (int i = 0; i < N; i++) {
            scan_int(&altura);
            raiz = inserir(raiz, altura);
        }

        primeiro_impresso = 1;
        imprimirEmOrdem(raiz);
        printf("\n");

        liberarArvore(raiz);
    }

    return 0;
}
