#incluir <stdio.h>
#incluir <string.h>

int contarDiamantes(char *str) {
    int contagem = 0;
    int i = 0;
    
    enquanto (str[i] != '\0') {
        se (str[i] == '<') {
            para (int j = i + 1; str[j] != '\0'; j++) {
                se (str[j] == '>') {
                    contar++; // Um ​​diamante foi encontrado
                    str[i] = '.'; // Marca o '<' como processado
                    str[j] = '.'; // Marca o '>' como processado
                    quebrar; // Só podemos contar um diamante por vez
                }
            }
        }
        eu++;
    }
    contagem de retorno;
}

int principal() {
    int N;
    scanf("%d", &N);
    getchar(); // Para extrair a nova linha após o número de casos

    para (int i = 0; i < N; i++) {
        char linha[1001]; // Máximo de 1000 caracteres + '\0'
        fgets(linha, 1001, stdin);

        // Remove o '\n' da string, se existir
        linha[strcspn(linha, "\n")] = '\0';

        int resultado = contarDiamantes(linha);
        printf("%d\n", resultado);
    }

    retornar 0;
}
