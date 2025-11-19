#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// --- Estrutura do Nó da Árvore ---
typedef struct No {
    char dado;           // O problema especifica letras (char)
    struct No *esq;      // Ponteiro para a subárvore esquerda
    struct No *dir;      // Ponteiro para a subárvore direita
} No;

// --- Variável Global para Controle de Espaços ---
// Usada para evitar "Presentation Error" (espaço no final da linha)
bool primeiro_elemento = true;

// --- Funções da Árvore ---

// Função para criar um novo nó
No* criar_no(char valor) {
    No* novo = (No*) malloc(sizeof(No));
    if (novo) {
        novo->dado = valor;
        novo->esq = NULL;
        novo->dir = NULL;
    }
    return novo;
}

// Função de Inserção (Regra da BST: Menores à esquerda, Maiores à direita)
No* inserir(No* raiz, char valor) {
    if (raiz == NULL) {
        return criar_no(valor);
    }
    
    if (valor < raiz->dado) {
        raiz->esq = inserir(raiz->esq, valor);
    } else if (valor > raiz->dado) {
        raiz->dir = inserir(raiz->dir, valor);
    }
    // Se for igual, não faz nada (elementos repetidos são ignorados conforme enunciado)
    
    return raiz;
}

// Função de Pesquisa
bool pesquisar(No* raiz, char valor) {
    if (raiz == NULL) return false;
    if (raiz->dado == valor) return true;
    
    if (valor < raiz->dado) {
        return pesquisar(raiz->esq, valor);
    } else {
        return pesquisar(raiz->dir, valor);
    }
}

// --- Funções de Percurso (Travessia) ---

// Helper para imprimir com formatação correta
void imprimir_dado(char c) {
    if (primeiro_elemento) {
        printf("%c", c);
        primeiro_elemento = false;
    } else {
        printf(" %c", c); // Espaço antes do caractere
    }
}

// 1. Pré-Fixa (Raiz, Esquerda, Direita)
void prefixa(No* raiz) {
    if (raiz == NULL) return;
    imprimir_dado(raiz->dado);
    prefixa(raiz->esq);
    prefixa(raiz->dir);
}

// 2. Infixa (Esquerda, Raiz, Direita) - Imprime ordenado
void infixa(No* raiz) {
    if (raiz == NULL) return;
    infixa(raiz->esq);
    imprimir_dado(raiz->dado);
    infixa(raiz->dir);
}

// 3. Pós-Fixa (Esquerda, Direita, Raiz)
void posfixa(No* raiz) {
    if (raiz == NULL) return;
    posfixa(raiz->esq);
    posfixa(raiz->dir);
    imprimir_dado(raiz->dado);
}

// Função para liberar a memória (Boa prática)
void liberar_arvore(No* raiz) {
    if (raiz == NULL) return;
    liberar_arvore(raiz->esq);
    liberar_arvore(raiz->dir);
    free(raiz);
}

// --- Função Principal ---
int main() {
    No* raiz = NULL;
    char comando[20]; // Buffer para ler o comando (I, P, INFIXA, etc.)
    char valor;

    // Lê o comando até o fim do arquivo (EOF)
    while (scanf("%s", comando) != EOF) {
        
        if (strcmp(comando, "I") == 0) {
            // Inserir
            scanf(" %c", &valor); // O espaço antes de %c ignora espaços em branco/quebra de linha
            raiz = inserir(raiz, valor);
        } 
        else if (strcmp(comando, "P") == 0) {
            // Pesquisar
            scanf(" %c", &valor);
            if (pesquisar(raiz, valor)) {
                printf("%c existe\n", valor);
            } else {
                printf("%c nao existe\n", valor);
            }
        } 
        else {
            // Comandos de Impressão
            // Reseta a flag para o início de uma nova linha de impressão
            primeiro_elemento = true; 

            if (strcmp(comando, "INFIXA") == 0) {
                infixa(raiz);
            } else if (strcmp(comando, "PREFIXA") == 0) {
                prefixa(raiz);
            } else if (strcmp(comando, "POSFIXA") == 0) {
                posfixa(raiz);
            }
            
            // Quebra de linha após listar os elementos
            printf("\n");
        }
    }

    liberar_arvore(raiz);
    return 0;
}
