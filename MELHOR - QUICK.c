#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    long tempoExecucao;
    long trocas;
    long comparacoes;
} Estatisticas;

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particionar(int arr[], int baixo, int alto, Estatisticas *stats) {
    int pivo = arr[alto];
    int j,i = (baixo - 1);

    for (j = baixo; j <= alto - 1; j++) {
        stats->comparacoes++;

        if (arr[j] <= pivo) {
            i++;
            stats->trocas++;
            trocar(&arr[i], &arr[j]);
        }
    }

    stats->trocas++;
    trocar(&arr[i + 1], &arr[alto]);

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
    // Tamanho do array que irá trocar para tamanhos de 10^3 / 10^4 / 10^5
    int tamanho = 1000;

    int arr[tamanho];
    for (i = 0; i < tamanho; i++) {
        arr[i] = i;
    }

    printf("Array original: \n", tamanho);
    printArray(arr, tamanho);

    Estatisticas stats;

    clock_t inicio = clock();
    quickSort(arr, 0, tamanho - 1, &stats);
    clock_t fim = clock();

    stats.tempoExecucao = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000;

    printf("Array ordenado: \n");
    printArray(arr, tamanho);

    // Imprime estatísticas
    printf("Estatisticas:\n");
    printf("Tempo de Execucao: %ld ms\n", stats.tempoExecucao);
    printf("Quantidade de Trocas: %ld\n", stats.trocas);
    printf("Quantidade de Comparacoes: %ld\n", stats.comparacoes);

    return 0;
}

