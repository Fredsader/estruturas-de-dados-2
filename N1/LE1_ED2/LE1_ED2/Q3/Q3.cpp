#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int priority;
    int order;
} PriorityQueueElement;

void criaHeap(PriorityQueueElement arr[], int pai, int fim) {
    PriorityQueueElement aux = arr[pai];
    int filho = 2 * pai + 1;
    while (filho <= fim) {
        if (filho < fim) {
            if (arr[filho].priority > arr[filho + 1].priority) {
                filho++;
            } else if (arr[filho].priority == arr[filho + 1].priority && arr[filho].order < arr[filho + 1].order) {
                filho++;
            }
        }
        if (aux.priority > arr[filho].priority || (aux.priority == arr[filho].priority && aux.order < arr[filho].order)) {
            arr[pai] = arr[filho];
            pai = filho;
            filho = 2 * pai + 1;
        } else {
            filho = fim + 1;
        }
    }
    arr[pai] = aux;
}

void heapSort(PriorityQueueElement arr[], int n) {
    int i;
    PriorityQueueElement aux;
    for (i = (n - 1) / 2; i >= 0; i--) {
        criaHeap(arr, i, n - 1);
    }
    for (i = n - 1; i >= 1; i--) {
        aux = arr[0];
        arr[0] = arr[i];
        arr[i] = aux;
        criaHeap(arr, 0, i - 1);
    }
}

int main() {
    // Construa o vetor inicial (prioridade e ordem de chegada)
    PriorityQueueElement input[] = {{5, 1}, {4, 2}, {3, 3}, {5, 4}};
    int n = sizeof(input) / sizeof(input[0]);

    // Imprima o vetor inicial
    printf("Vetor Inicial:\n");
    for (int i = 0; i < n; i++) {
        printf("(%d-%d) ", input[i].priority, input[i].order);
    }
    printf("\n");

    // Transforme o vetor em um vetor com prioridade final
    for (int i = 0; i < n; i++) {
        input[i].priority = (input[i].priority * 100) + (10 - input[i].order);
    }

    // Imprima o vetor com prioridade final
    printf("Vetor com Prioridade Final:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", input[i].priority);
    }
    printf("\n");

    // Ordene o vetor com base na prioridade final usando HeapSort
    heapSort(input, n);

    // Imprima o vetor ordenado por prioridade
    printf("Vetor Ordenado por Prioridade Final:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", input[i].priority);
    }
    printf("\n");

    return 0;
}

