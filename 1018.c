#include <stdio.h>

int main() {
    int N;
    int notas_100, notas_50, notas_20, notas_10, notas_5, notas_2, notas_1;

    scanf("%d", &N);

    printf("%d\n", N);

    notas_100 = N / 100;
    N = N % 100;

    notas_50 = N / 50;
    N = N % 50;

    notas_20 = N / 20;
    N = N % 20;

    notas_10 = N / 10;
    N = N % 10;

    notas_5 = N / 5;
    N = N % 5;

    notas_2 = N / 2;
    N = N % 2;

    notas_1 = N;

    printf("%d nota(s) de R$ 100,00\n", notas_100);
    printf("%d nota(s) de R$ 50,00\n", notas_50);
    printf("%d nota(s) de R$ 20,00\n", notas_20);
    printf("%d nota(s) de R$ 10,00\n", notas_10);
    printf("%d nota(s) de R$ 5,00\n", notas_5);
    printf("%d nota(s) de R$ 2,00\n", notas_2);
    printf("%d nota(s) de R$ 1,00\n", notas_1);

    return 0;
}
