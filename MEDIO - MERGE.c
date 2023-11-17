#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    long tempoExecucao;
    long trocas;
    long comparacoes;
} Estatisticas;

void merge(int arr[], int baixo, int meio, int alto, Estatisticas *stats) {
    int i, j, k;
    int n1 = meio - baixo + 1;
    int n2 = alto - meio;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++) {
        L[i] = arr[baixo + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[meio + 1 + j];
    }

    i = 0; 
    j = 0; 
    k = baixo;

    while (i < n1 && j < n2) {
        stats->comparacoes++;

        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        stats->trocas++;
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int baixo, int alto, Estatisticas *stats) {
    if (baixo < alto) {
        int meio = baixo + (alto - baixo) / 2;

        mergeSort(arr, baixo, meio, stats);
        mergeSort(arr, meio + 1, alto, stats);

        merge(arr, baixo, meio, alto, stats);
    }
}

void printArray(int arr[], int n) {
	int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    int i, n = 1000; // Tamanho do array aqui que irá trocar para tamanhos de 10^3 / 10^4 / 10^5

    int arr[n];

    for (i = 0; i < n; i++) {
        arr[i] = rand();
    }

    printf("Array original: \n", n);
    printArray(arr, n);

    Estatisticas stats;

    clock_t inicio = clock();
    mergeSort(arr, 0, n - 1, &stats);
    clock_t fim = clock();

    printf("Array ordenado: \n");
    printArray(arr, n);

    printf("Estatisticas:\n");
    printf("Tempo de Execucao: %ld ms\n", ((fim - inicio) * 1000) / CLOCKS_PER_SEC);
    printf("Quantidade de Trocas: %ld\n", stats.trocas);
    printf("Quantidade de Comparacoes: %ld\n", stats.comparacoes);

    return 0;
}

