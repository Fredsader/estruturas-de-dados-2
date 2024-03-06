#include <stdio.h>
#include <stdlib.h>
#include "ArvoreAVL.h"

int main()
{
   // Defini��es de vari�veis
	ArvAVL* MinhaArvore;
    int num;
    int i;
    srand(123);
   // Cria a �rvore bin�ria de busca
	printf("Comeca o teste da Arvore AVL\n");

	MinhaArvore = cria_ArvAVL();

	for(i = 0; i<10000; i++){
		int num = (rand() % 10000);
		insere_ArvAVL(MinhaArvore, num); 
	}

	printf("\n A arvore contem os seguintes elementos:\n");
	emOrdem_ArvAVL(MinhaArvore);
	printf("A altura da arvore e: %d\n",altura_ArvAVL(MinhaArvore));
	return 0;
}
