#include <stdio.h>
#include <limits.h>

/**
 * Função principal que lê o tamanho do vetor N,
 * lê os N elementos, encontra o menor valor e sua posição,
 * e imprime o resultado.
 */
int main() {
    int N;
    
    // 1. Leitura do valor N (1 < N < 1000)
    // A função scanf retorna o número de itens lidos com sucesso.
    if (scanf("%d", &N) != 1) {
        // Trata erro de leitura ou EOF na primeira linha
        return 1;
    }
    
    // Ignorando a validação de 1 < N < 1000 no código final
    // para focar no requisito principal, mas em um ambiente real
    // esta validação seria importante.

    // Declaração do vetor X de tamanho N
    int X[N];
    
    int menor_valor = INT_MAX; // Inicializa com o maior inteiro possível
    int menor_posicao = -1;    // Inicializa com uma posição inválida
    
    // 2. Leitura dos N valores para o vetor X e busca pelo menor elemento
    for (int i = 0; i < N; i++) {
        // Tenta ler o próximo valor e armazena em X[i]
        if (scanf("%d", &X[i]) != 1) {
            // Se a leitura falhar antes de ler N elementos, sai.
            return 1;
        }
        
        // 3. Verifica se o elemento lido é o menor até agora
        if (X[i] < menor_valor) {
            menor_valor = X[i];
            menor_posicao = i;
        }
    }
    
    // 4. Saída (imprime o resultado)
    printf("Menor valor: %d\n", menor_valor);
    printf("Posicao: %d\n", menor_posicao);
    
    return 0;
}
