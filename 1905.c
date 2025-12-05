#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

int grid[MAX][MAX]; // Matriz do labirinto
int visited[MAX][MAX]; // Vetor para marcar os nós visitados

// Movimentos possíveis: Cima, Baixo, Esquerda, Direita
int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// Definindo uma estrutura de fila
typedef struct {
    int x[MAX * MAX];
    int y[MAX * MAX];
    int front;
    int rear;
} Queue;

// Função para inicializar a fila
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = 0;
}

// Função para verificar se a fila está vazia
int isEmpty(Queue *q) {
    return q->front == q->rear;
}

// Função para enfileirar um elemento
void enqueue(Queue *q, int x, int y) {
    q->x[q->rear] = x;
    q->y[q->rear] = y;
    q->rear++;
}

// Função para desenfileirar um elemento
void dequeue(Queue *q, int *x, int *y) {
    *x = q->x[q->front];
    *y = q->y[q->front];
    q->front++;
}

// Função BFS para encontrar o caminho da polícia até os ladrões
int bfs() {
    Queue q;
    initQueue(&q);
    memset(visited, 0, sizeof(visited)); // Inicializa o vetor de visitados
    
    // Começa na posição (0,0)
    enqueue(&q, 0, 0);
    visited[0][0] = 1;

    while (!isEmpty(&q)) {
        int x, y;
        dequeue(&q, &x, &y);

        // Se chegou na posição (4,4), a polícia venceu
        if (x == 4 && y == 4) {
            return 1; // Polícia vence
        }

        // Verifica os movimentos possíveis
        for (int i = 0; i < 4; i++) {
            int nx = x + directions[i][0];
            int ny = y + directions[i][1];

            // Verifica se a posição está dentro dos limites e é válida
            if (nx >= 0 && nx < MAX && ny >= 0 && ny < MAX && grid[nx][ny] == 0 && !visited[nx][ny]) {
                visited[nx][ny] = 1;
                enqueue(&q, nx, ny);
            }
        }
    }

    return 0; // Ladrões vencem se não houver caminho
}

int main() {
    int T;
    scanf("%d", &T); // Lê o número de casos de teste

    while (T--) {
        // Lê a matriz 5x5
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                scanf("%d", &grid[i][j]);
            }
        }

        // Chama a função BFS e imprime o resultado
        if (bfs()) {
            printf("COPS\n"); // Polícia vence
        } else {
            printf("ROBBERS\n"); // Ladrões vencem
        }
    }

    return 0;
}
