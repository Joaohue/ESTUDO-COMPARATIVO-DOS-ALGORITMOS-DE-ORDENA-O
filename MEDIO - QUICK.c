#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    long tempoExecucao;
    long trocas;
    long comparacoes;
} Estatisticas;

void trocar(int *a, int *b, Estatisticas *stats) {
    int temp = *a;
    *a = *b;
    *b = temp;

    stats->trocas++;
}

int particionar(int arr[], int baixo, int alto, Estatisticas *stats) {
    int pivo = arr[alto];
    int j,i = (baixo - 1);

    for (j = baixo; j <= alto - 1; j++) {
        stats->comparacoes++;

        if (arr[j] <= pivo) {
            i++;
            trocar(&arr[i], &arr[j], stats);
        }
    }

    trocar(&arr[i + 1], &arr[alto], stats);

    return (i + 1);
}

void quickSort(int arr[], int baixo, int alto, Estatisticas *stats) {
    if (baixo < alto) {
        int pivo = particionar(arr, baixo, alto, stats);

        quickSort(arr, baixo, pivo - 1, stats);
        quickSort(arr, pivo + 1, alto, stats);
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
	int i;
    int n = 1000;   // Tamanho do array aqui que irá trocar para tamanhos de 10^3 / 10^4 / 10^5

    int arr[n];

    for (i = 0; i < n; i++) {
        arr[i] = rand();
    }

    printf("Array original: \n", n);
    printArray(arr, n);

    Estatisticas stats;

    clock_t inicio = clock();
    quickSort(arr, 0, n - 1, &stats);
    clock_t fim = clock();

    printf("Array ordenado: \n");
    printArray(arr, n);

    printf("Estatisticas:\n");
    printf("Tempo de Execucao: %ld ms\n", ((fim - inicio) * 1000) / CLOCKS_PER_SEC);
    printf("Quantidade de Trocas: %ld\n", stats.trocas);
    printf("Quantidade de Comparacoes: %ld\n", stats.comparacoes);

    return 0;
}

