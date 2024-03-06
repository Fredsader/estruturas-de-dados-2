#include <stdio.h>
#include <stdlib.h>
#include "ArvoreAVL.h"


// Fun��o auxiliar para imprimir espa�o em branco com base no n�vel
void imprimeEspaco(int nivel) {
    for (int i = 0; i < nivel * 4; i++) {
        printf(" ");
    }
}

// Fun��o para imprimir a �rvore AVL de forma hier�rquica
void imprimeArvoreAVLHierarquica(struct NO* raiz, int nivel) {
    if (raiz == NULL) {
        return;
    }

    imprimeArvoreAVLHierarquica(raiz->dir, nivel + 1);

    imprimeEspaco(nivel);
    printf("%d (%d) [%d]\n", nivel, raiz->info, fatorBalanceamento_NO(raiz));

    imprimeArvoreAVLHierarquica(raiz->esq, nivel + 1);
}

int main() {
    ArvAVL* MinhaArvore;
    int num;
    int i;
    srand(123);

    printf("Comeca o teste da Arvore AVL\n");

    MinhaArvore = cria_ArvAVL();

    for (i = 0; i < 10; i++) {
        int num = (rand() % 10);
        insere_ArvAVL(MinhaArvore, num);
    }

    printf("�rvore AVL impressa hierarquicamente:\n");
    imprimeArvoreAVLHierarquica(*MinhaArvore, 0);

    printf("A altura da arvore eh: %d\n", altura_ArvAVL(MinhaArvore));

    return 0;
}

