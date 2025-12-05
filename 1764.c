#include <stdio.h>
#include <stdlib.h>

#define MAX_M 40005
#define MAX_N 50005

typedef struct {
    int u, v, w;
} Aresta;

Aresta arestas[MAX_N];
int pai[MAX_M];

int compare(const void *a, const void *b) {
    return ((Aresta*)a)->w - ((Aresta*)b)->w;
}

int find(int i) {
    if (pai[i] == i)
        return i;
    return pai[i] = find(pai[i]);
}

void unite(int i, int j) {
    int raiz_i = find(i);
    int raiz_j = find(j);
    if (raiz_i != raiz_j) {
        pai[raiz_i] = raiz_j;
    }
}

int main() {
    int M, N;

    while (scanf("%d %d", &M, &N) && (M != 0 || N != 0)) {
        for (int i = 0; i < N; i++) {
            scanf("%d %d %d", &arestas[i].u, &arestas[i].v, &arestas[i].w);
        }

        qsort(arestas, N, sizeof(Aresta), compare);

        for (int i = 0; i < M; i++) {
            pai[i] = i;
        }

        int soma = 0;
        int arestas_selecionadas = 0;

        for (int i = 0; i < N; i++) {
            if (find(arestas[i].u) != find(arestas[i].v)) {
                unite(arestas[i].u, arestas[i].v);
                soma += arestas[i].w;
                arestas_selecionadas++;
            }
           
            if (arestas_selecionadas == M - 1) break;
        }

        printf("%d\n", soma);
    }

    return 0;
}
