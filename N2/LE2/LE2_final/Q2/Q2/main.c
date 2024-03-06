#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "ArvoreAVL.h"
#include "ArvoreBinaria.h"

int main()
{
    setlocale(LC_ALL, "");
   // Defini��es de vari�veis
	ArvAVL *MinhaArvoreAVL;
	ArvBin *MinhaArvoreBinaria;
    int num;
    int i;
    srand(123);

   // Cria a �rvore AVL
    MinhaArvoreAVL = cria_ArvAVL();
    for (i = 0; i < 50; i++) {
        int num = (rand() % 100);
        insere_ArvAVL(MinhaArvoreAVL, num);
    }

    // Cria a �rvore bin�ria
    MinhaArvoreBinaria = cria_ArvBin();
    srand(123);
    for (int i = 0; i < 50; i++) {
        int num = (rand() % 100);
        insere_ArBin(MinhaArvoreBinaria, num);
    }

    // Imprime os percursos
    printf("\n\nEm ordem (AVL):\n");
    emOrdem_ArvAVL(MinhaArvoreAVL);

    printf("\n\nEm ordem (BST):\n");
    emOrdem_ArvBin(MinhaArvoreBinaria);


	printf("\n\nPr�-ordem (AVL):\n");
    preOrdem_ArvAVL(MinhaArvoreAVL);

    printf("\n\nPr�-ordem (BST):\n");
    preOrdem_ArvBin(MinhaArvoreBinaria);


    printf("\n\nP�s-ordem (AVL):\n");
    posOrdem_ArvAVL(MinhaArvoreAVL);

    printf("\n\nP�s-ordem (BST):\n");
    posOrdem_ArvBin(MinhaArvoreBinaria);
    printf("\n\n");

    libera_ArvBin(MinhaArvoreBinaria);

	return 0;
}
