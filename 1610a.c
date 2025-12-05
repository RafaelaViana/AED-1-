#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 10005
#define MAXM 30005

int head[MAXN];
int to[MAXM];
int next_edge[MAXM];
int edge_count;
int grau_entrada[MAXN];
int fila[MAXN];

void init_graph(int n) {
    edge_count = 0;
    memset(head, -1, (n + 1) * sizeof(int));
    memset(grau_entrada, 0, (n + 1) * sizeof(int));
}

void add_edge(int u, int v) {
    to[edge_count] = v;
    next_edge[edge_count] = head[u];
    head[u] = edge_count++;
    grau_entrada[v]++; 
}

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;

    while (T--) {
        int N, M;
        scanf("%d %d", &N, &M);

        init_graph(N);

        for (int i = 0; i < M; i++) {
            int A, B;
            scanf("%d %d", &A, &B);
            add_edge(B, A);
        }

        int inicio_fila = 0;
        int fim_fila = 0;

        for (int i = 1; i <= N; i++) {
            if (grau_entrada[i] == 0) {
                fila[fim_fila++] = i;
            }
        }

        int processados = 0;

        while (inicio_fila < fim_fila) {
            int u = fila[inicio_fila++];
            processados++;

            for (int e = head[u]; e != -1; e = next_edge[e]) {
                int v = to[e];
                grau_entrada[v]--;
                if (grau_entrada[v] == 0) {
                    fila[fim_fila++] = v;
                }
            }
        }

        if (processados < N) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
    }

    return 0;
}
