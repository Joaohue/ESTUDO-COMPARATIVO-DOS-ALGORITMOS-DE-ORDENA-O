#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    long tempoExecucao;
    long trocas;
    long comparacoes;
} Estatisticas;

void selectionSort(int arr[], int n, Estatisticas *stats) {
    int i, j, min_idx;
    stats->trocas = 0;
    stats->comparacoes = 0;

    clock_t inicio = clock();

    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            stats->comparacoes++;
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        
        if (min_idx != i) {
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;

            stats->trocas++;
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

int main() {
    int i;
    // Tamanho do array aqui que irá trocar para tamanhos de 10^3 / 10^4 / 10^5
    int tamanho = 1000;

    
    int arr[tamanho];
    for (i = 0; i < tamanho; i++) {
        arr[i] = i;  
    }

    printf("Array original: \n", tamanho);
    printArray(arr, tamanho);

    
    Estatisticas stats;

    selectionSort(arr, tamanho, &stats);

    printf("Array ordenado: \n");
    printArray(arr, tamanho);

    // Imprime estatísticas
    printf("Estatisticas:\n");
    printf("Tempo de Execucao: %ld ms\n", stats.tempoExecucao);
    printf("Quantidade de Trocas: %ld\n", stats.trocas);
    printf("Quantidade de Comparacoes: %ld\n", stats.comparacoes);

    return 0;
}
