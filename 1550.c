#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10005 

int fila[MAX];
int distancia[MAX]; 

int inverter(int n) {
    int rev = 0;
    while (n > 0) {
        rev = rev * 10 + (n % 10);
        n /= 10;
    }
    return rev;
}

int bfs(int inicio, int fim) {
 
    memset(distancia, -1, sizeof(distancia));
    
    int inicio_fila = 0;
    int fim_fila = 0;

    fila[fim_fila++] = inicio;
    distancia[inicio] = 0;

    while (inicio_fila < fim_fila) {
        int atual = fila[inicio_fila++];

       
        if (atual == fim) {
            return distancia[atual];
        }

        int prox_soma = atual + 1;
        if (prox_soma < MAX && distancia[prox_soma] == -1) {
            distancia[prox_soma] = distancia[atual] + 1;
            fila[fim_fila++] = prox_soma;
        }

   
        int prox_inv = inverter(atual);
        if (prox_inv < MAX && distancia[prox_inv] == -1) {
            distancia[prox_inv] = distancia[atual] + 1;
            fila[fim_fila++] = prox_inv;
        }
    }
    return -1; 
}

int main() {
    int T;
  
    scanf("%d", &T);

    while (T--) {
        int A, B;
 
        scanf("%d %d", &A, &B);

        int resultado = bfs(A, B);
        
        printf("%d\n", resultado);
    }

    return 0;
}
