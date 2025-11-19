#include <stdio.h>
#include <string.h> // Para a função memset

int main() {
    int N, M;

    // 1. Ler N (quantidade inicial)
    scanf("%d", &N);

    // Array para guardar a fila inicial (N <= 50000)
    int fila_inicial[50000];
    
    // Array de verificação para os IDs (IDs 1 a 100000)
    // Precisamos de 100001 posições para acessar o índice 100000
    int saiu_da_fila[100001];

    // 2. IMPORTANTE: Zerar o array de verificação
    // Arrays locais não são inicializados automaticamente
    // memset(ponteiro, valor_byte, numero_de_bytes)
    memset(saiu_da_fila, 0, sizeof(saiu_da_fila));

    // 1b. Ler a fila inicial
    for (int i = 0; i < N; i++) {
        scanf("%d", &fila_inicial[i]);
    }

    // 3. Ler M (quantidade que saiu)
    scanf("%d", &M);

    // 3b. Ler e marcar quem saiu
    for (int i = 0; i < M; i++) {
        int id_saiu;
        scanf("%d", &id_saiu);
        saiu_da_fila[id_saiu] = 1; // 1 = true (essa pessoa saiu)
    }

    // 4. Verificar e Imprimir a fila final
    
    // Flag para controlar o espaço na impressão
    int primeiro_a_imprimir = 1; 

    for (int i = 0; i < N; i++) {
        int id_atual = fila_inicial[i];

        // Se a pessoa NÃO saiu (valor é 0)
        if (saiu_da_fila[id_atual] == 0) {
            
            // Se for o primeiro número, não imprime espaço antes
            if (primeiro_a_imprimir) {
                printf("%d", id_atual);
                primeiro_a_imprimir = 0; // Os próximos não são mais o primeiro
            } else {
                // Imprime espaço antes dos números seguintes
                printf(" %d", id_atual);
            }
        }
    }

    // Imprime a quebra de linha final
    printf("\n");

    return 0;
}
