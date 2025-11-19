#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Definindo um tamanho máximo para as estruturas (limitado a 1000 operações de entrada)
#define MAX_SIZE 1000

// --- Funções Auxiliares para Simular Estruturas ---

// Troca dois elementos em um array
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Restaura a propriedade Max-Heap a partir de um índice
void max_heapify(int arr[], int size, int i) {
    int maior = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    if (esquerda < size && arr[esquerda] > arr[maior]) {
        maior = esquerda;
    }

    if (direita < size && arr[direita] > arr[maior]) {
        maior = direita;
    }

    if (maior != i) {
        swap(&arr[i], &arr[maior]);
        max_heapify(arr, size, maior);
    }
}

// Insere um elemento na Fila de Prioridade
void pq_push(int arr[], int *size, int valor) {
    if (*size >= MAX_SIZE) return;
    
    arr[*size] = valor;
    int i = *size;
    (*size)++;
    
    while (i != 0 && arr[(i - 1) / 2] < arr[i]) {
        swap(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Remove e retorna o maior elemento (raiz) da Fila de Prioridade
int pq_pop(int arr[], int *size) {
    if (*size <= 0) return -1;

    int raiz = arr[0];
    
    arr[0] = arr[*size - 1];
    (*size)--;
    
    max_heapify(arr, *size, 0);
    
    return raiz;
}

// --- Função Principal ---

int main() {
    int n;
    
    // Loop para processar múltiplos casos de teste até o Fim do Arquivo (EOF)
    while (scanf("%d", &n) != EOF) {
        // 1. Inicialização das Estruturas
        int stack_arr[MAX_SIZE];
        int stack_size = 0; 

        int queue_arr[MAX_SIZE];
        int queue_head = 0;
        int queue_tail = 0;
        
        int pq_arr[MAX_SIZE];
        int pq_size = 0;

        bool is_stack = true;
        bool is_queue = true;
        bool is_pq = true;
        
        // 2. Processamento das N Operações
        for (int i = 0; i < n; i++) {
            int comando, valor;
            
            if (scanf("%d %d", &comando, &valor) != 2) break;

            if (comando == 1) {
                // Comando 1: Inserção
                if (is_stack && stack_size < MAX_SIZE) {
                    stack_arr[stack_size++] = valor;
                }
                
                if (is_queue && queue_tail < MAX_SIZE) {
                    queue_arr[queue_tail++] = valor;
                }
                
                if (is_pq) {
                    pq_push(pq_arr, &pq_size, valor);
                }
            } else if (comando == 2) {
                // Comando 2: Remoção/Teste
                
                // Teste Pilha
                if (is_stack) {
                    if (stack_size == 0 || stack_arr[stack_size - 1] != valor) {
                        is_stack = false;
                    } else {
                        stack_size--;
                    }
                }

                // Teste Fila
                if (is_queue) {
                    if (queue_head == queue_tail || queue_arr[queue_head] != valor) {
                        is_queue = false;
                    } else {
                        queue_head++;
                    }
                }

                // Teste Fila de Prioridade
                if (is_pq) {
                    if (pq_size == 0 || pq_arr[0] != valor) {
                        is_pq = false;
                    } else {
                        pq_pop(pq_arr, &pq_size);
                    }
                }
            }
        } // Fim do loop for (processa N operações)

        // 3. Determinação da Saída
        int valid_count = is_stack + is_queue + is_pq;

        if (valid_count == 0) {
            printf("impossible\n");
        } else if (valid_count > 1) {
            printf("not sure\n");
        } else {
            if (is_stack) {
                printf("stack\n");
            } else if (is_queue) {
                printf("queue\n");
            } else {
                printf("priority queue\n");
            }
        }
    } // <-- Faltava o fechamento do while (scanf... != EOF)
    
    return 0;
} // <-- Faltava o fechamento da função main()
