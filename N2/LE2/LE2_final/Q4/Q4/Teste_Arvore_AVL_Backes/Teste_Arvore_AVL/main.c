#include <stdio.h>
#include <stdlib.h>
#include "ArvoreAVL.h"

int main()
{
   // Defini��es de vari�veis
	MinhaArvore = cria_ArvAVL();

	printf("A altura da arvore e: %d\n",altura_ArvAVL(MinhaArvore));
	return 0;
}