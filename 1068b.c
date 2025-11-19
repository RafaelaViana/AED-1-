#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char expressao[1005]; // Buffer para a string (limite de 1000 + segurança)

    // fgets lê até o final da linha ou EOF.
    // O loop continua enquanto houver entrada para ler.
    while (fgets(expressao, sizeof(expressao), stdin) != NULL) {
        
        int balanco = 0;
        bool possivel = true;
        
        // Percorre cada caractere da string lida
        for (int i = 0; expressao[i] != '\0'; i++) {
            if (expressao[i] == '(') {
                balanco++;
            } 
            else if (expressao[i] == ')') {
                balanco--;
                
                // Se o balanço ficar negativo, temos um ')' sem um '(' antes dele
                if (balanco < 0) {
                    possivel = false;
                    break; // Não precisa continuar verificando
                }
            }
        }

        // Para ser correto, não pode ter ficado negativo em nenhum momento
        // E o balanço final deve ser 0 (todos os abertos foram fechados)
        if (possivel && balanco == 0) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }

    return 0;
}
