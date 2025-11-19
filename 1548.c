#include <stdio.h>
#include <stdlib.h> // Para a função qsort

/**
 * Função de comparação para qsort.
 * Ordena em ordem DECRESCENTE (do maior para o menor).
 */
int comparar_decrescente(const void *a, const void *b) {
    // Converte os ponteiros genéricos de volta para ponteiros de int
    int int_a = *((int*)a);
    int int_b = *((int*)b);

    // Se b é maior que a, b vem primeiro (retorna positivo)
    if (int_a < int_b) return 1;
    // Se a é maior que b, a vem primeiro (retorna negativo)
    if (int_a > int_b) return -1;
    // Se são iguais
    return 0;
    
    // Uma forma mais curta de escrever o mesmo:
    // return (*(int*)b - *(int*)a);
}

int main() {
    int N; // Número de casos de teste
    scanf("%d", &N);

    // Loop para cada caso de teste
    while (N--) {
        int M; // Número de alunos
        scanf("%d", &M);

        // Arrays para as notas (tamanho máximo 1000)
        int ordem_chegada[1000];
        int ordem_notas[1000];

        // 1. Lê as notas e preenche os dois arrays
        for (int i = 0; i < M; i++) {
            scanf("%d", &ordem_chegada[i]);
            ordem_notas[i] = ordem_chegada[i]; // Copia para o outro array
        }

        // 2. Ordena o array 'ordem_notas' em ordem decrescente
        // qsort(array, num_elementos, tamanho_cada_elemento, funcao_comparacao)
        qsort(ordem_notas, M, sizeof(int), comparar_decrescente);

        // 3. Compara os dois arrays e conta as posições iguais
        int alunos_sem_troca = 0;
        for (int i = 0; i < M; i++) {
            if (ordem_chegada[i] == ordem_notas[i]) {
                alunos_sem_troca++;
            }
        }

        // 4. Imprime o resultado para este caso de teste
        printf("%d\n", alunos_sem_troca);
    }

    return 0;
}
