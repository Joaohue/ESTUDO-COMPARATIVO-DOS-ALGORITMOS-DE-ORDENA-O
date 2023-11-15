#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    long tempoExecucao;
    long trocas;
    long comparacoes;
} Estatisticas;

void insertionSort(int arr[], int n, Estatisticas *stats) {
    int i, chave, j;
    stats->trocas = 0;
    stats->comparacoes = 0;

    clock_t inicio = clock();

    for (i = 1; i < n; i++) {
        chave = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > chave) { // Modificado para ordem crescente
            arr[j + 1] = arr[j];
            j = j - 1;

            stats->trocas++;
            stats->comparacoes++;
        }
        arr[j + 1] = chave;
        stats->trocas++;
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
    int tamanho = 1000; // Tamanho do array

    // Array em ordem decrescente (pior caso)
    int arr[tamanho];
    for (i = 0; i < tamanho; i++) {
        arr[i] = tamanho - i;
    }

    printf("Array original (pior caso - ordem decrescente): \n");
    printArray(arr, tamanho);

    // Estrutura para armazenar estatísticas
    Estatisticas stats;

    insertionSort(arr, tamanho, &stats);

    printf("Array ordenado: \n");
    printArray(arr, tamanho);

    // Imprime estatísticas
    printf("Estatisticas:\n");
    printf("Tempo de Execucao: %ld ms\n", stats.tempoExecucao);
    printf("Quantidade de Trocas: %ld\n", stats.trocas);
    printf("Quantidade de Comparacoes: %ld\n", stats.comparacoes);

    return 0;
}

