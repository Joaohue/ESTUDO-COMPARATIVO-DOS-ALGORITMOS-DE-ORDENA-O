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

        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j = j - 1;

            stats->trocas++;
            stats->comparacoes++;
        }
        arr[j + 1] = chave;
        if (i != j + 1) {
            stats->trocas++;
        } else {
            stats->comparacoes++;  // Incrementa comparação no caso de movimentação sem troca
        }
    }

    clock_t fim = clock();

    stats->tempoExecucao = (fim - inicio) * 1000 / CLOCKS_PER_SEC; // Corrigido para calcular corretamente o tempo em milissegundos
}

void printArray(int arr[], int n) {
	int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void generateSortedArray(int arr[], int n) {
	int i;
    for (i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
}

int main() {
    //Tamanho do array aqui que ira trocar para tamanhos de 10^3 / 10^4 / 10^5
    int tamanho = 1000;

    // Array de tamanho ordenado (melhor caso)
    int arr[tamanho];

    // Gerar array ordenado
    generateSortedArray(arr, tamanho);

    printf("Array original (tamanho %d - Melhor Caso): \n", tamanho);
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

