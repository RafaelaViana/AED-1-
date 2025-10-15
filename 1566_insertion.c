#include <stdio.h>

// Define as alturas mínima e máxima
#define ALTURA_MIN 20
#define ALTURA_MAX 230

int main() {
    // Para leitura e escrita mais rápidas
    
    int NC; // Número de casos de teste (cidades)
    scanf("%d", &NC);

    while (NC--) {
        int N; // Quantidade de pessoas na cidade
        scanf("%d", &N);

        int altura_lida;

        for (int i = 0; i < N; i++) {
            scanf("%d", &altura_lida);
            contagem_alturas[altura_lida]++;
        }

        int primeiro_a_imprimir = 1;
        
        for (int h = ALTURA_MIN; h <= ALTURA_MAX; h++) {
  
            for (int i = 0; i < contagem_alturas[h]; i++) {
                if (primeiro_a_imprimir) {
                    printf("%d", h);
                    primeiro_a_imprimir = 0;
                } else {
                    printf(" %d", h);
                }
            }
        }
        printf("\n"); // Nova linha ao final de cada caso de teste
    }

    return 0;
}
