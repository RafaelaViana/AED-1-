#include <stdio.h>
#include <stdlib.h>

#define MAX_N 305
#define MAX_ID 400005 // (2*300+1) * (2*300+2) ≈ 360,000


typedef struct {
    int u, v;
} Aresta;


Aresta arestas_custo0[MAX_ID];
Aresta arestas_custo1[MAX_ID];
int qtd0, qtd1;


int pai[MAX_ID];


void init_dsu(int n) {
    for (int i = 0; i <= n; i++) {
        pai[i] = i;
    }
}


int find(int i) {
    if (pai[i] == i)
        return i;
    return pai[i] = find(pai[i]);
}


int unite(int i, int j) {
    int raiz_i = find(i);
    int raiz_j = find(j);
    if (raiz_i != raiz_j) {
        pai[raiz_i] = raiz_j;
        return 1;
    }
    return 0;
}


int get_id(int r, int c, int N) {
    // Limites da lagoa: linhas 0 a 2N, colunas 0 a 2N+1
    if (r <= 0 || r >= 2 * N || c <= 0 || c >= 2 * N + 1) {
        return 0; // Nó unificado da borda (Outside)
    }

    int width = 2 * N + 2;
    return r * width + c;
}

int main() {
    int N;
    char buffer[MAX_N]; // Buffer para leitura das strings

    while (scanf("%d", &N) != EOF) {
        int max_nos = (2 * N + 2) * (2 * N + 2);
        init_dsu(max_nos);
        qtd0 = 0;
        qtd1 = 0;

        for (int i = 1; i < 2 * N; i++) {
            scanf("%s", buffer);
            
            for (int j = 1; j <= N; j++) {
                char tipo = buffer[j - 1];
                int r_centro, c_centro;

            
                if (i % 2 != 0) { // Linha ímpar
                    r_centro = i;
                    c_centro = 2 * j - 1;
                } else { // Linha par
                    r_centro = i;
                    c_centro = 2 * j;
                }

                
                int u_vert = get_id(r_centro - 1, c_centro, N);
                int v_vert = get_id(r_centro + 1, c_centro, N);

               
                int u_hor = get_id(r_centro, c_centro - 1, N);
                int v_hor = get_id(r_centro, c_centro + 1, N);

                if (tipo == 'V') {
                    // Se já é V: Custo V = 0, Custo H = 1
                    arestas_custo0[qtd0].u = u_vert;
                    arestas_custo0[qtd0].v = v_vert;
                    qtd0++;

                    arestas_custo1[qtd1].u = u_hor;
                    arestas_custo1[qtd1].v = v_hor;
                    qtd1++;
                } else { // tipo == 'H'
                    // Se já é H: Custo H = 0, Custo V = 1
                    arestas_custo0[qtd0].u = u_hor;
                    arestas_custo0[qtd0].v = v_hor;
                    qtd0++;

                    arestas_custo1[qtd1].u = u_vert;
                    arestas_custo1[qtd1].v = v_vert;
                    qtd1++;
                }
            }
        }

        int switches = 0;

   
        for (int k = 0; k < qtd0; k++) {
            unite(arestas_custo0[k].u, arestas_custo0[k].v);
        }


        for (int k = 0; k < qtd1; k++) {
        
            if (unite(arestas_custo1[k].u, arestas_custo1[k].v)) {
                switches++;
            }
        }

        printf("%d\n", switches);
    }

    return 0;
}
