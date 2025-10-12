#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, inst = 1;
    scanf("%d", &n);

    while (n--) {
        int **mat = (int **) malloc(9 * sizeof(int *));
        for (int i = 0; i < 9; i++) {
            mat[i] = (int *) malloc(9 * sizeof(int));
        }

        int valido = 1;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &mat[i][j]);
            }
        }

        for (int i = 0; i < 9 && valido; i++) {
            int freq[10] = {0};
            for (int j = 0; j < 9; j++) {
                if (freq[mat[i][j]]) valido = 0;
                freq[mat[i][j]] = 1;
            }
        }

        for (int j = 0; j < 9 && valido; j++) {
            int freq[10] = {0};
            for (int i = 0; i < 9; i++) {
                if (freq[mat[i][j]]) valido = 0;
                freq[mat[i][j]] = 1;
        }
  }

        for (int linhaBase = 0; linhaBase < 9 && valido; linhaBase += 3) {
            for (int colBase = 0; colBase < 9 && valido; colBase += 3) {
                int freq[10] = {0};
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        int v = mat[linhaBase+i][colBase+j];
                        if (freq[v]) valido = 0;
                        freq[v] = 1;
                    }
                }
            }
        }

        printf("Instancia %d\n", inst++);
        if (valido) printf("SIM\n\n");
        else        printf("NAO\n\n");

        for (int i = 0; i < 9; i++) {
            free(mat[i]);
        }
        free(mat);
    }

    return 0;
}
