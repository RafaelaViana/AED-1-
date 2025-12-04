#include <stdio.h>
#include <stdlib.h>

#define MAX 1025

// Estrutura para guardar as coordenadas na pilha
typedef struct {
    int x, y;
} Ponto;

char imagem[MAX][MAX];

Ponto pilha[MAX * MAX]; 
int topo = 0;

// Funções da Pilha
void push(int x, int y) {
    pilha[topo].x = x;
    pilha[topo].y = y;
    topo++;
}

Ponto pop() {
    topo--;
    return pilha[topo];
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    // Leitura da Imagem
    for (int i = 0; i < N; i++) {
        scanf("%s", imagem[i]); 
       
    }

    int cliques = 0;
    
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    // Varre toda a matriz
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            

            if (imagem[i][j] == '.') {
                cliques++;
                
                // Inicia o processo iterativo
                push(i, j);
                imagem[i][j] = 'o'; 

                while (topo > 0) {
                    Ponto p = pop();

                   
                    for (int k = 0; k < 4; k++) {
                        int nx = p.x + dx[k];
                        int ny = p.y + dy[k];

                          if (nx >= 0 && nx < N && ny >= 0 && ny < M && imagem[nx][ny] == '.') {
                            imagem[nx][ny] = 'o'; 
                            push(nx, ny);
                        }
                    }
                }
            }
        }
    }

    printf("%d\n", cliques);

    return 0;
}
