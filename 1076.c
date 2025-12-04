#include <stdio.h>
#include <string.h>

#define MAX_NOS 100

int main() {
    int T; 
    scanf("%d", &T);

    while (T--) {
        int inicio;
        scanf("%d", &inicio);

        int V, A; // Vértices e Arestas
        scanf("%d %d", &V, &A);

        int grafo[MAX_NOS][MAX_NOS];
        memset(grafo, 0, sizeof(grafo));

        for (int i = 0; i < A; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            
    
            grafo[u][v] = 1;
            grafo[v][u] = 1;
        }

        int movimentos = 0;

        for (int i = 0; i < MAX_NOS; i++) {
            for (int j = 0; j < MAX_NOS; j++) {
                if (grafo[i][j] == 1) {
                    movimentos++;
                }
            }
        }

        printf("%d\n", movimentos);
    }

    return 0;
}
