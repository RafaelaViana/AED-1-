#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Função para contar ocorrências de um número
int contNum(int vet[], int tamVet, int num) {
    int cont = 0;
    for (int i = 0; i < tamVet; i++) {
        if (vet[i] == num) {
            cont++;
        }
    }
    return cont;
}

// Função de ordenação Selection Sort
void selectionSort(int vet[], int tamVet) {
    for (int i = 0; i < tamVet - 1; i++) {
        int min = i;
        for (int j = i + 1; j < tamVet; j++) {
            if (vet[j] < vet[min]) {
                min = j;
            }
        }
        int aux = vet[i];
        vet[i] = vet[min];
        vet[min] = aux;
    }
}

// Copia um subvetor do vetor original
void copiaVetor(int vetOrig[], int vetDest[], int limInf, int limSup) {
    for (int i = limInf, j = 0; i <= limSup; i++, j++) {
        vetDest[j] = vetOrig[i];
    }
}

int main() {
    int tamVet, rodadas;
    scanf("%d %d", &tamVet, &rodadas);

    int vet[tamVet];
    for (int i = 0; i < tamVet; i++) {
        scanf("%d", &vet[i]);
    }

    for (int r = 0; r < rodadas; r++) {
        int limInf, limSup, kMenor, guga, dabriel;
        scanf("%d %d %d %d %d", &limInf, &limSup, &kMenor, &guga, &dabriel);

        int tamIntervalo = limSup - limInf + 1;
        int intervalo[tamIntervalo];
        copiaVetor(vet, intervalo, limInf - 1, limSup - 1);

        selectionSort(intervalo, tamIntervalo);

        int menor = intervalo[kMenor - 1];
        int contKEsimo = contNum(intervalo, tamIntervalo, menor);

        int difGuga = abs(contKEsimo - guga);
        int difDabriel = abs(contKEsimo - dabriel);

        char result = 'E';
        if (difGuga < difDabriel) {
            result = 'G';
        } else if (difDabriel < difGuga) {
            result = 'D';
        }

        printf("%d %d %c\n", menor, contKEsimo, result);
    }

    return 0;
}
