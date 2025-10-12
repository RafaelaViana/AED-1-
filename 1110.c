#include <stdio.h>
#include <stdlib.h>

#define MAX 51  // Corrigido: precisa de 1 posição extra para fila circular funcionar com 50 cartas

typedef struct {
    int dados[MAX];
    int inicio, fim;
} Fila;

// Inicializa a fila
void inicializarFila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
}

// Verifica se a fila está vazia
int filaVazia(Fila *f) {
    return f->inicio == f->fim;
}

// Verifica se a fila está cheia
int filaCheia(Fila *f) {
    return (f->fim + 1) % MAX == f->inicio;
}

// Insere um elemento no fim da fila
void enfileirar(Fila *f, int valor) {
    if (!filaCheia(f)) {
        f->dados[f->fim] = valor;
        f->fim = (f->fim + 1) % MAX;
    }
}

// Remove o elemento do início da fila
int desenfileirar(Fila *f) {
    if (!filaVazia(f)) {
        int valor = f->dados[f->inicio];
        f->inicio = (f->inicio + 1) % MAX;
        return valor;
    }
    return -1; // erro
}

// Retorna o tamanho atual da fila
int tamanhoFila(Fila *f) {
    if (f->fim >= f->inicio) {
        return f->fim - f->inicio;
    } else {
        return MAX - f->inicio + f->fim;
    }
}

int main() {
    int n;
    while (scanf("%d", &n) && n != 0) {
        Fila f;
        inicializarFila(&f);

        // Coloca todas as cartas na fila
        for (int i = 1; i <= n; i++) {
            enfileirar(&f, i);
        }

        printf("Discarded cards:");
        int primeira = 1;

        // Enquanto restarem mais de 1 carta
        while (tamanhoFila(&f) > 1) {
            // Remove e mostra a carta descartada
            int descartada = desenfileirar(&f);
            if (primeira) {
                printf(" %d", descartada);
                primeira = 0;
            } else {
                printf(", %d", descartada);
            }

            // Move a próxima carta para o fim da fila
            int movida = desenfileirar(&f);
            enfileirar(&f, movida);
        }

        // Mostra a última carta
        printf("\nRemaining card: %d\n", desenfileirar(&f));
    }
    return 0;
}
