#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOTAL 1000005

char pool[MAX_TOTAL];
char *joias[MAX_TOTAL];
char buffer[MAX_TOTAL];

int compare(const void *a, const void *b) {
    const char *strA = *(const char **)a;
    const char *strB = *(const char **)b;
    return strcmp(strA, strB);
}

int main() {
    int n = 0;
    int pool_pos = 0;

    while (scanf("%s", buffer) != EOF) {
        int len = strlen(buffer);

        joias[n] = &pool[pool_pos];
        strcpy(joias[n], buffer);
        
        pool_pos += len + 1;
        n++;
    }

    if (n == 0) {
        printf("0\n");
        return 0;
    }

    qsort(joias, n, sizeof(char *), compare);

    int distintas = 1;
    for (int i = 1; i < n; i++) {
        if (strcmp(joias[i], joias[i-1]) != 0) {
            distintas++;
        }
    }

    printf("%d\n", distintas);

    return 0;
}
