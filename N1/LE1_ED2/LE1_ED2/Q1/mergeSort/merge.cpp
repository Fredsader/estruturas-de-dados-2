#include <stdlib.h>
#include <stdio.h>


void merge (int lista[], int inicio, int meio, int fim){
	
	int n1 = meio - inicio + 1;
	int n2 = fim - meio;
	
	int L[n1], R[n2];
	
	int i, j;
	
	for (i = 0; i < n1; i++){
		L[i] = lista[inicio + i];
	}
	for (j = 0; j < n2; j++){
		R[j] = lista[meio + 1 + j];
	}
	
	i = 0, j = 0; int k = inicio;
	
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]){
			lista[k] = L[i];
			i++;
		}else{
			lista[k] = R[j];
			j++;
		}
		k++;
	}
	
	// Copiar os elementos restantes de L[], se houver
    while (i < n1) {
        lista[k] = L[i];
        i++;
        k++;
    }

    // Copiar os elementos restantes de R[], se houver
    while (j < n2) {
        lista[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int lista[], int inicio, int fim){
	
	if (inicio < fim){
		int meio = inicio + (fim - inicio) / 2;
		
		mergeSort(lista, inicio, meio);
		mergeSort(lista, meio + 1, fim);
		merge(lista, inicio, meio, fim);
	}
}


int main() {
    int lista[] = {12, 11, 13, 5, 6, 7};
    int arrSize = sizeof(lista) / sizeof(lista[0]);

    printf("Array original:\n");
    for (int i = 0; i < arrSize; i++)
        printf("%d ", lista[i]);

    mergeSort(lista, 0, arrSize - 1);

    printf("\nArray ordenado:\n");
    for (int i = 0; i < arrSize; i++)
        printf("%d ", lista[i]);

    return 0;
}
