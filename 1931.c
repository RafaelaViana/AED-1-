#include <stdio.h>
#include <stdlib.h>

#define MAX_C 10005
#define INF 1000000000

typedef struct Node {
    int destino;
    int peso;
    struct Node* proximo;
} Node;

Node* adj[MAX_C];

void adicionarAresta(int u, int v, int peso) {
    Node* novo = (Node*)malloc(sizeof(Node));
    novo->destino = v;
    novo->peso = peso;
    novo->proximo = adj[u];
    adj[u] = novo;

    Node* novo2 = (Node*)malloc(sizeof(Node));
    novo2->destino = u;
    novo2->peso = peso;
    novo2->proximo = adj[v];
    adj[v] = novo2;
}

typedef struct {
    int u;
    int paridade;
    int custo;
} Estado;

Estado heap[MAX_C * 20];
int heap_size = 0;

void push(int u, int paridade, int custo) {
    int i = heap_size++;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p].custo <= custo) break;
        heap[i] = heap[p];
        i = p;
    }
    heap[i].u = u;
    heap[i].paridade = paridade;
    heap[i].custo = custo;
}

Estado pop() {
    Estado ret = heap[0];
    Estado x = heap[--heap_size];
    int i = 0;
    while (i * 2 + 1 < heap_size) {
        int filho = i * 2 + 1;
        if (filho + 1 < heap_size && heap[filho + 1].custo < heap[filho].custo)
            filho++;
        if (heap[filho].custo >= x.custo) break;
        heap[i] = heap[filho];
        i = filho;
    }
    heap[i] = x;
    return ret;
}

int dist[MAX_C][2]; 

int main() {
    int C, V;

    if (scanf("%d %d", &C, &V) != 2) return 0;

    for (int i = 0; i <= C; i++) {
        adj[i] = NULL;
    }

    for (int i = 0; i < V; i++) {
        int u, v, g;
        scanf("%d %d %d", &u, &v, &g);
        adicionarAresta(u, v, g);
    }

    for (int i = 1; i <= C; i++) {
        dist[i][0] = INF;
        dist[i][1] = INF;
    }

    dist[1][0] = 0;
    push(1, 0, 0);

    while (heap_size > 0) {
        Estado atual = pop();
        int u = atual.u;
        int par = atual.paridade;
        int custo = atual.custo;

        if (custo > dist[u][par]) continue;

        Node* temp = adj[u];
        while (temp != NULL) {
            int v = temp->destino;
            int peso = temp->peso;
            
            int prox_par = 1 - par; 

            if (dist[u][par] + peso < dist[v][prox_par]) {
                dist[v][prox_par] = dist[u][par] + peso;
                push(v, prox_par, dist[v][prox_par]);
            }
            temp = temp->proximo;
        }
    }

    int resposta = dist[C][0];

    if (resposta == INF) {
        printf("-1\n");
    } else {
        printf("%d\n", resposta);
    }

    return 0;
}
