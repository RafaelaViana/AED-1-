#include <stdio.h>

int valido(int m[9][9]) {
    int i, j, k, l;
    int visto[10];
    // checar as linhas
    for (i = 0; i < 9; i++) {
        for (k = 1; k <= 9; k++) visto[k] = 0;
        for (j = 0; j < 9; j++) {
            if (visto[m[i][j]]) return 0;
            visto[m[i][j]] = 1;
        }
    }
    // checar as colunas
    for (j = 0; j < 9; j++) {
        for (k = 1; k <= 9; k++) visto[k] = 0;
        for (i = 0; i < 9; i++) {
            if (visto[m[i][j]]) return 0;
            visto[m[i][j]] = 1;
        }
    }
    // checar as  subgrades 3x3
    for (i = 0; i < 9; i += 3) {
        for (j = 0; j < 9; j += 3) {
            for (k = 1; k <= 9; k++) visto[k] = 0;
            for (k = 0; k < 3; k++) {
                for (l = 0; l < 3; l++) {
                    int num = m[i + k][j + l];
                    if (visto[num]) return 0;
                    visto[num] = 1;
                }
            }
        }
    }

    return 1;
}

int main() {
    int n, i, j, caso = 1;
    scanf("%d", &n);

    while (n--) {
        int m[9][9];
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
                scanf("%d", &m[i][j]);
            }
        }

        printf("Instancia %d\n", caso++);
        if (valido(m))
            printf("SIM\n\n");
        else
            printf("NAO\n\n");
    }

    return 0;
}
