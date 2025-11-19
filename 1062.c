#include <stdio.h>

// --- Implementação de uma Pilha Simples ---
// Usaremos um array global para a pilha, já que N <= 1000
int stack[1001];
int top; // Índice do elemento no topo da pilha

// Inicializa a pilha (deixa vazia)
void stack_init() {
    top = -1;
}

// Verifica se a pilha está vazia
int stack_is_empty() {
    return top == -1;
}

// Adiciona (empurra) um item ao topo da pilha
void stack_push(int value) {
    // Não é necessário verificar o estouro, pois N <= 1000
    stack[++top] = value;
}

// Remove (desempilha) um item do topo da pilha
int stack_pop() {
    if (stack_is_empty()) {
        return -1; // Sinal de erro (não deve acontecer no problema)
    }
    return stack[top--];
}

// Retorna o item no topo da pilha sem removê-lo
int stack_peek() {
    if (stack_is_empty()) {
        return -1; // Sinal de erro
    }
    return stack[top];
}
// --- Fim da Implementação da Pilha ---


int main() {
    int N; // Quantidade de vagões
    int target_permutation[1001]; // A permutação de saída desejada
    int i;

    // Loop principal: lê o N de cada bloco
    // Continua enquanto N for lido com sucesso E N não for 0
    while (scanf("%d", &N) == 1 && N != 0) {
        
        // Loop secundário: lê cada permutação para o bloco N
        while (1) {
            // Lê o primeiro vagão da permutação de saída
            scanf("%d", &target_permutation[0]);
            
            // Se o primeiro vagão for 0, é o fim deste bloco
            if (target_permutation[0] == 0) {
                break; // Sai do loop secundário
            }

            // Lê o restante (N-1) dos vagões da permutação
            for (i = 1; i < N; i++) {
                scanf("%d", &target_permutation[i]);
            }

            // --- Início da Simulação ---

            stack_init(); // Esvazia a estação
            int incoming_wagon = 1; // O próximo vagão a chegar da Direção A
            int target_index = 0;   // O índice do vagão que queremos na Direção B
            int possible = 1;       // Flag: 1 = Yes, 0 = No

            // Continua enquanto não tivermos formado toda a saída B
            while (target_index < N) {
                // O vagão que precisamos para a saída B
                int needed_wagon = target_permutation[target_index];

                // Caso 1: O vagão que precisamos está no topo da estação
                if (!stack_is_empty() && stack_peek() == needed_wagon) {
                    stack_pop();      // Retira da estação
                    target_index++;   // Move para o próximo vagão da saída
                }
                // Caso 2: Precisamos pegar vagões da Direção A
                else if (incoming_wagon <= N) {
                    
                    // Move vagões de A para a estação até encontrar o que precisamos
                    while (incoming_wagon <= N) {
                        if (incoming_wagon == needed_wagon) {
                            // Achamos! "Envia" para B (sem empilhar)
                            incoming_wagon++; // Próximo vagão de A será N+1
                            target_index++;   // Move para o próximo vagão da saída
                            break; // Para de mover vagões de A por agora
                        } else {
                            // Vagão errado. Envia para a estação.
                            stack_push(incoming_wagon);
                            incoming_wagon++;
                        }
                    }
                }
                // Caso 3: Não está na estação E não há mais vagões em A
                else {
                    // Estamos presos. É impossível.
                    possible = 0;
                    break; // Para a simulação
                }
            }
            
            // --- Fim da Simulação ---

            if (possible) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
        
        // Após o '0' que indica o fim do bloco, imprime uma linha em branco
        printf("\n");
    }

    return 0;
}
