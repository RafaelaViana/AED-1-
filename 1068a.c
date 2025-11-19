#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 1005 // Tamanho máximo da expressão + margem

// --- Definição da Estrutura Pilha ---
typedef struct {
    char itens[MAX]; // O vetor que armazena os dados
    int topo;        // Índice do elemento no topo
} Pilha;

// Função para inicializar a pilha
void inicializar(Pilha *p) {
    p->topo = -1; // -1 indica pilha vazia (índice 0 é o primeiro elemento)
}

// Função para verificar se está vazia
bool estaVazia(Pilha *p) {
    return p->topo == -1;
}

// Função Push (Empilhar)
void push(Pilha *p, char c) {
    if (p->topo < MAX - 1) {
        p->topo++;
        p->itens[p->topo] = c;
    }
}

// Função Pop (Desempilhar)
void pop(Pilha *p) {
    if (!estaVazia(p)) {
        p->topo--;
    }
}

// --- Função Principal ---
int main() {
    char expressao[MAX];
    Pilha p;

    // Lê cada linha da entrada até o fim do arquivo (EOF)
    while (fgets(expressao, MAX, stdin) != NULL) {
        
        inicializar(&p); // Reseta a pilha para a nova expressão
        bool erro = false;

        // Percorre a string caractere por caractere
        for (int i = 0; expressao[i] != '\0'; i++) {
            
            if (expressao[i] == '(') {
                // Se for abertura, joga na pilha
                push(&p, '(');
            } 
            else if (expressao[i] == ')') {
