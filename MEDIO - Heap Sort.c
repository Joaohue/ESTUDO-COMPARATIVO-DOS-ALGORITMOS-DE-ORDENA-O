#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    long tempoExecucao;
    long trocas;
    long comparacoes;
} Estatisticas;

void heapify(int arr[], int n, int i, Estatisticas *stats) {
    int maior = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;


    stats->comparacoes++;

    if (esquerda < n && arr[esquerda] > arr[maior]) {
        maior = esquerda;
    }

    stats->comparacoes++;

    if (direita < n && arr[direita] > arr[maior]) {
        maior = direita;
    }

    if (maior != i) {
        stats->trocas++;

        int temp = arr[i];
        arr[i] = arr[maior];
        arr[maior] = temp;

        heapify(arr, n, maior, stats);
    }
}

void heapSort(int arr[], int n, Estatisticas *stats) {
	int i;

    for (i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, stats);
    }

    for (i = n - 1; i >= 0; i--) {
   
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0, stats);
    }
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

    // Array de tamanho 1.000
    int arr[tamanho];

    // Preenchendo o array com valores aleatórios (ou conforme necessário)
    for (i = 0; i < tamanho; i++) {
        arr[i] = rand();
    }

    printf("Array original (tamanho %d): \n", tamanho);
    printArray(arr, tamanho);

    Estatisticas stats;

    clock_t inicio = clock();
    heapSort(arr, tamanho, &stats);
    clock_t fim = clock();

    printf("Array ordenado: \n");
    printArray(arr, tamanho);

    printf("Estatisticas:\n");
    printf("Tempo de Execucao: %ld ms\n", ((fim - inicio) * 1000) / CLOCKS_PER_SEC);
    printf("Quantidade de Trocas: %ld\n", stats.trocas);
    printf("Quantidade de Comparacoes: %ld\n", stats.comparacoes);

    return 0;
}

