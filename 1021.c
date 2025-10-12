#include <stdio.h>
#include <math.h>

int main() {
    double valor;
    int notas, moedas;
    int resto;

    scanf("%lf", &valor);

    
    int valorCentavos = (int) round(valor * 100);

    printf("NOTAS:\n");

    notas = valorCentavos / 10000;  
    printf("%d nota(s) de R$ 100.00\n", notas);
    valorCentavos %= 10000;

    notas = valorCentavos / 5000;   
    printf("%d nota(s) de R$ 50.00\n", notas);
    valorCentavos %= 5000;

    notas = valorCentavos / 2000;  
    printf("%d nota(s) de R$ 20.00\n", notas);
    valorCentavos %= 2000;

    notas = valorCentavos / 1000;
    printf("%d nota(s) de R$ 10.00\n", notas);
    valorCentavos %= 1000;

    notas = valorCentavos / 500;   
    printf("%d nota(s) de R$ 5.00\n", notas);
    valorCentavos %= 500;

    notas = valorCentavos / 200;   
     printf("%d nota(s) de R$ 2.00\n", notas);
    valorCentavos %= 200;

    printf("MOEDAS:\n");

    moedas = valorCentavos / 100;   
    printf("%d moeda(s) de R$ 1.00\n", moedas);
    valorCentavos %= 100;

    moedas = valorCentavos / 50;    
    printf("%d moeda(s) de R$ 0.50\n", moedas);
    valorCentavos %= 50;

    moedas = valorCentavos / 25;   
    printf("%d moeda(s) de R$ 0.25\n", moedas);
    valorCentavos %= 25;

    moedas = valorCentavos / 10;    
    printf("%d moeda(s) de R$ 0.10\n", moedas);
    valorCentavos %= 10;

    moedas = valorCentavos / 5;    
    printf("%d moeda(s) de R$ 0.05\n", moedas);
    valorCentavos %= 5;

    moedas = valorCentavos;         
    printf("%d moeda(s) de R$ 0.01\n", moedas);

    return 0;
}
