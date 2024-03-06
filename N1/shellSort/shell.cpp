#include<stdlib.h>
#include<stdio.h>
#include<time.h>

void aloca_vetor(int **v, int n){
	*v = (int*)malloc(n*sizeof(int));
}

void preenche_vetor(int *v, int n){
	int i;
	srand(time(NULL));
	
	for(i=0;i < n;i++){
		v[i] = rand () %100;
	}
}

void shellSort (int *v, int n){
	int i, j, atual, h;
	h = 1;
	while(h < n/3){
		h = 3 * h + 1;
	}
	while(h > 0){
		for(i = h ;i < n; i++){
			atual = v[i];
			j = i;
			while(j >= h && atual < v[j - h]){
				v[j] = v[j - h];
				j = j - h;
			}
			v[j] = atual;
		}
		h = (h-1)/3;
	}
}

void imprime_vetor(int *v, int n){
	int i;
	for (i=0;i<n;i++){
		printf("%d ", v[i]);
	}
}
int main(){
	int *v, n;
	
	n = 10;
	
	aloca_vetor(&v,n);
	preenche_vetor (v,n);
	shellSort(v, n);
	imprime_vetor(v, n);
	free(v);
	
}
