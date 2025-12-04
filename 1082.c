#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_V 26

// Variáveis Globais
int adj[MAX_V][MAX_V];   
int visitado[MAX_V];     
int V, E;                


char lista_componente[MAX_V];
int tam_lista;

// Função de comparação para o qsort 
int compara_char(const void *a, const void *b) {
    return (*(char*)a - *(char*)b);
}

// Busca em Profundidade (DFS)
void DFS(int u) {
    visitado[u] = 1;
    
    // Adiciona o nó atual na lista 
    lista_componente[tam_lista] = u + 'a'; // Converte 0 -> 'a', 1 -> 'b'
    tam_lista++;

    // Verifica todos
    for (int v = 0; v < V; v++) {
        if (adj[u][v] == 1 && visitado[v] == 0) {
            DFS(v);
        }
    }
}

int main() {
    int N; // Casos de teste
    scanf("%d", &N);

    for (int caso = 1; caso <= N; caso++) {
        scanf("%d %d", &V, &E);

 
        memset(adj, 0, sizeof(adj));
        memset(visitado, 0, sizeof(visitado));

        // Leitura das arestas
        for (int i = 0; i < E; i++) {
            char u_char, v_char;
   
            scanf(" %c %c", &u_char, &v_char);
            
            int u = u_char - 'a';
            int v = v_char - 'a';

            // Grafo não direcionado (vai e volta)
            adj[u][v] = 1;
            adj[v][u] = 1;
        }

        printf("Case #%d:\n", caso);

        int num_componentes = 0;


        for (int i = 0; i < V; i++) {
            if (visitado[i] == 0) {
                // Achamos um novo componente!
                num_componentes++;
                
                tam_lista = 0;
                DFS(i);

             
                qsort(lista_componente, tam_lista, sizeof(char), compara_char);

        
                for (int k = 0; k < tam_lista; k++) {
                    printf("%c,", lista_componente[k]);
                }
                printf("\n");
            }
        }

        printf("%d connected components\n\n", num_componentes);
    }

    return 0;
}
