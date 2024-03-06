#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"
#include <time.h>

int main()
{
	int i;
	srand(123);
   // Definições de variáveis
	ArvBin* MinhaArvore;
    int num;
   // Cria a árvore binária de busca
	printf("Comeca o teste da arvore binaria de busca\n");

	MinhaArvore = cria_ArvBin();

	for(i = 0; i<10000; i++){
		int num = (rand() % 10000);
		insere_ArBin(MinhaArvore, num); 
	}


	printf("\n A arvore contem os seguintes elementos:\n");
	emOrdem_ArvBin(MinhaArvore);
	printf("\n A arvore possui altura %d .\n", altura_ArvBin(MinhaArvore));
	return 0;
	
	libera_ArvBin(MinhaArvore);
}
