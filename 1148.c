#include <stdio.h>

#define MAX 505
#define INFINITO 0x3f3f3f3f

int matriz_tempos[MAX][MAX];
int conexoes[MAX][MAX];
int tempo_minimo[MAX];
int verificado[MAX];

int calcular_tempo(int n, int origem, int destino) {
    int i, v, j;
   
    for (i = 1; i <= n; i++) {
        tempo_minimo[i] = INFINITO;
        verificado[i] = 0;
    }
    tempo_minimo[origem] = 0;

    for (i = 0; i < n; i++) {
        int cidade_atual = -1;
        int menor = INFINITO;

        for (j = 1; j <= n; j++) {
            if (!verificado[j] && tempo_minimo[j] < menor) {
                menor = tempo_minimo[j];
                cidade_atual = j;
            }
        }

        if (cidade_atual == -1 || tempo_minimo[cidade_atual] == INFINITO) break;
       
        verificado[cidade_atual] = 1;

        for (v = 1; v <= n; v++) {
            if (matriz_tempos[cidade_atual][v] != INFINITO &&
                tempo_minimo[v] > tempo_minimo[cidade_atual] + matriz_tempos[cidade_atual][v]) {
                tempo_minimo[v] = tempo_minimo[cidade_atual] + matriz_tempos[cidade_atual][v];
            }
        }
    }

    return tempo_minimo[destino];
}

int main() {
    int N, E, K;
    int x, y, h, O, D;
    int i, j, k;
    int primeiro = 1;

    while (scanf("%d %d", &N, &E) && N != 0) {
        for (i = 0; i <= N; i++) {
            for (j = 0; j <= N; j++) {
                matriz_tempos[i][j] = INFINITO;
                conexoes[i][j] = 0;
            }
            conexoes[i][i] = 1;
        }

        for (i = 0; i < E; i++) {
            scanf("%d %d %d", &x, &y, &h);
            if (h < matriz_tempos[x][y]) {
                matriz_tempos[x][y] = h;
            }
            conexoes[x][y] = 1;
        }

        for (k = 1; k <= N; k++) {
            for (i = 1; i <= N; i++) {
                if (conexoes[i][k]) {
                    for (j = 1; j <= N; j++) {
                        if (conexoes[k][j]) {
                            conexoes[i][j] = 1;
                        }
                    }
                }
            }
        }

        for (i = 1; i <= N; i++) {
            for (j = 1; j <= N; j++) {
                if (matriz_tempos[i][j] != INFINITO) {
                    if (conexoes[i][j] && conexoes[j][i]) {
                        matriz_tempos[i][j] = 0;
                    }
                }
            }
        }

        if (!primeiro) {
            printf("\n");
        }
        primeiro = 0;

        scanf("%d", &K);
        while (K--) {
            scanf("%d %d", &O, &D);
            int res = calcular_tempo(N, O, D);

            if (res == INFINITO) {
                printf("Nao e possivel entregar a carta\n");
            } else {
                printf("%d\n", res);
            }
        }
    }

    printf("\n");

    return 0;
}
