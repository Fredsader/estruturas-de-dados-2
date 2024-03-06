#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void criaHeap (int *vet, int pai, int fim){
     int aux = vet[pai];
     int filho = 2* pai + 1;
     while (filho <= fim){
           if (filho < fim){
              if (vet[filho] < vet[filho+1]){
                        filho++;
              }
           }
           if (aux < vet[filho]){
              vet[pai] = vet[filho];
              pai = filho;
              filho = 2 * pai + 1;
           }else{
              filho = fim + 1;
           }       
     }
     vet[pai] = aux;
}

void heapSort (int *vet, int N){
	 int i, aux;
	 for(i = (N - 1)/2;i >= 0; i--){
	 	   criaHeap(vet, i, N-1);
     }
     for(i = N - 1; i >= 1; i--){
	 	   aux = vet[0];
	 	   vet[0] = vet[i];
	 	   vet[i] = aux;
	 	   criaHeap(vet, 0, i - 1);
	 }
}

int main (){
	int vet[6], N = 6, i;
	
	srand(time(NULL));
	
	for(i = 0; i < N; i++){
		vet[i] = rand() % 100;
		printf("%d ", vet[i]);
	}
	
	heapSort(vet, N);
	printf("\n");
	for(i = 0; i < N; i++){
		printf("%d ", vet[i]);
	}
		
}
