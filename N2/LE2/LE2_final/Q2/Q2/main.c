#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "ArvoreAVL.h"
#include "ArvoreBinaria.h"

int main()
{
    setlocale(LC_ALL, "");
   // Definições de variáveis
	ArvAVL *MinhaArvoreAVL;
	ArvBin *MinhaArvoreBinaria;
    int num;
    int i;
    srand(123);

   // Cria a árvore AVL
    MinhaArvoreAVL = cria_ArvAVL();
    for (i = 0; i < 50; i++) {
        int num = (rand() % 100);
        insere_ArvAVL(MinhaArvoreAVL, num);
    }

    // Cria a árvore binária
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


	printf("\n\nPré-ordem (AVL):\n");
    preOrdem_ArvAVL(MinhaArvoreAVL);

    printf("\n\nPré-ordem (BST):\n");
    preOrdem_ArvBin(MinhaArvoreBinaria);


    printf("\n\nPós-ordem (AVL):\n");
    posOrdem_ArvAVL(MinhaArvoreAVL);

    printf("\n\nPós-ordem (BST):\n");
    posOrdem_ArvBin(MinhaArvoreBinaria);
    printf("\n\n");

    libera_ArvBin(MinhaArvoreBinaria);

	return 0;
}
