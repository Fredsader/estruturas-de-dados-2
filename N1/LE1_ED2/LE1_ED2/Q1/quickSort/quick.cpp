#include <stdio.h>
#include <stdlib.h>


void swap (int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int lista[], int inicio, int fim){
	int pivo = lista[fim];
	
	int i = (inicio - 1); int j;
	for (j = inicio; j <= fim - 1; j++){
		if(lista[j] < pivo){
			i++;
			swap(&lista[i], &lista[j]);
		}
	}
	swap(&lista[i + 1], &lista[fim]);
	return(i + 1);
	
}




void quickSort (int lista [], int inicio, int fim){
	if (inicio < fim){
		int pivo;
		
		pivo = partition(lista, inicio, fim);
		
		quickSort(lista, inicio, pivo - 1);
		quickSort(lista, pivo + 1, fim);
		
	}
}

int main() {
    int lista[] = {10, 7, 8, 9, 1, 5};
    int arrSize = sizeof(lista) / sizeof(lista[0]);

    printf("Array original:\n");
    for (int i = 0; i < arrSize; i++)
        printf("%d ", lista[i]);

    quickSort(lista, 0, arrSize - 1);

    printf("\nArray ordenado:\n");
    for (int i = 0; i < arrSize; i++)
        printf("%d ", lista[i]);

    return 0;
}
