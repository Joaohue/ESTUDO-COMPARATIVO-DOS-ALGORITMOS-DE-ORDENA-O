#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    long tempoExecucao;
    long trocas;
    long comparacoes;
} Estatisticas;

void bubbleSort(int arr[], int n, Estatisticas *stats) {
    int i, j;
    stats->trocas = 0;
    stats->comparacoes = 0;

    clock_t inicio = clock();

    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            stats->comparacoes++;

            if (arr[j] > arr[j+1]) {
                
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

                stats->trocas++;
            }
        }
    }

    clock_t fim = clock();

    stats->tempoExecucao = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000;
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
    // Tamanho do array aqui que irá trocar para tamanhos de 10^3 / 10^4 / 10^5
    int tamanho = 1000;

    int arr[tamanho];
    for (i = 0; i < tamanho; i++) {
        arr[i] = rand();
    }

    printf("Array original: \n", tamanho);
    printArray(arr, tamanho);

    Estatisticas stats;

    bubbleSort(arr, tamanho, &stats);

    printf("Array ordenado: \n");
    printArray(arr, tamanho);

    // Imprime estatísticas
    printf("Estatisticas:\n");
    printf("Tempo de Execucao: %ld ms\n", stats.tempoExecucao);
    printf("Quantidade de Trocas: %ld\n", stats.trocas);
    printf("Quantidade de Comparacoes: %ld\n", stats.comparacoes);

    return 0;
}

