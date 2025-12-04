#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_N 255
#define INF 1000000000

// Estrutura para aresta na lista 
typedef struct {
    int v;
    int peso;
} Aresta;

// Estrutura para o Heap (
typedef struct {
    int u;
    int dist;
} NoHeap;

// Variáveis Globais
int N, M, C, K;
int adj[MAX_N][MAX_N]; 
int dist[MAX_N];
int custo_rota[MAX_N]; 


NoHeap heap[MAX_N * MAX_N];
int heap_size;

void push(int u, int d) {
    int i = heap_size++;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p].dist <= d) break;
        heap[i] = heap[p];
        i = p;
    }
    heap[i].u = u;
    heap[i].dist = d;
}

NoHeap pop() {
    NoHeap ret = heap[0];
    int i = 0;
    int last = --heap_size;
    NoHeap x = heap[last];
    
    while (i * 2 + 1 < heap_size) {
        int child = i * 2 + 1;
        if (child + 1 < heap_size && heap[child + 1].dist < heap[child].dist)
            child++;
        if (heap[child].dist >= x.dist) break;
        heap[i] = heap[child];
        i = child;
    }
    heap[i] = x;
    return ret;
}


void dijkstra(int inicio) {
   
    for (int i = 0; i < N; i++) dist[i] = INF;
    
    dist[inicio] = 0;
    heap_size = 0;
    push(inicio, 0);

    while (heap_size > 0) {
        NoHeap atual = pop();
        int u = atual.u;
        int d = atual.dist;

        if (d > dist[u]) continue;

     
        if (u < C) continue;

      
        for (int v = 0; v < N; v++) {
            if (adj[u][v] != -1) { // Se existe aresta
                int peso = adj[u][v];
                
               
                if (dist[u] + peso < dist[v]) {
                    dist[v] = dist[u] + peso;
                    push(v, dist[v]);
                }
            }
        }
    }
}

int main() {
    while (scanf("%d %d %d %d", &N, &M, &C, &K) && (N || M || C || K)) {
        

        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                adj[i][j] = -1;

        // Leitura das estradas
        for (int i = 0; i < M; i++) {
            int u, v, p;
            scanf("%d %d %d", &u, &v, &p);
            adj[u][v] = p;
            adj[v][u] = p;
        }

       
        custo_rota[C-1] = 0; 
        for (int i = C - 2; i >= 0; i--) {
           
            custo_rota[i] = adj[i][i+1] + custo_rota[i+1];
        }

    
        dijkstra(K);

         int min_total = INF;
        
        for (int i = 0; i < C; i++) {
            if (dist[i] != INF) {
                int total = dist[i] + custo_rota[i];
                if (total < min_total) {
                    min_total = total;
                }
            }
        }

        printf("%d\n", min_total);
    }

    return 0;
}
