#include <stdio.h>

// Função para encontrar o maior número no array
int encontrarMaior(int arr[], int n) {
    int maior = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maior) {
            maior = arr[i];
        }
    }
    return maior;
}

// Função para realizar a ordenação Counting Sort em um dígito específico
void countingSort(int arr[], int n, int exp) {
    int saida[n]; // Array de saída temporário
    int contador[10] = {0}; // Contagem de dígitos de 0 a 9

    // Contagem de dígitos
    for (int i = 0; i < n; i++) {
        contador[(arr[i] / exp) % 10]++;
    }

    // Atualização do contador para indicar a posição correta do dígito
    for (int i = 1; i < 10; i++) {
        contador[i] += contador[i - 1];
    }

    // Construção do array de saída
    for (int i = n - 1; i >= 0; i--) {
        saida[contador[(arr[i] / exp) % 10] - 1] = arr[i];
        contador[(arr[i] / exp) % 10]--;
    }

    // Copiar o array de saída de volta para o array original
    for (int i = 0; i < n; i++) {
        arr[i] = saida[i];
    }
}

// Função para realizar a ordenação RadixSort
void radixSort(int arr[], int n) {
    int maior = encontrarMaior(arr, n);
    
    // Aplicar o Counting Sort para cada posição de dígito, começando pelo menos significativo
    for (int exp = 1; maior / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

// Função para imprimir um array
void imprimirArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array original: \n");
    imprimirArray(arr, n);
    
    radixSort(arr, n);
    
    printf("Array ordenado: \n");
    imprimirArray(arr, n);
    
    return 0;
}

