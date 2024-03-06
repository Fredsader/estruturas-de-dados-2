#include <stdio.h>
#include <stdlib.h>
#include "ArvoreAVL.h"


// Função auxiliar para imprimir espaço em branco com base no nível
void imprimeEspaco(int nivel) {
    for (int i = 0; i < nivel * 4; i++) {
        printf(" ");
    }
}

// Função para imprimir a árvore AVL de forma hierárquica
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

    printf("Árvore AVL impressa hierarquicamente:\n");
    imprimeArvoreAVLHierarquica(*MinhaArvore, 0);

    printf("A altura da arvore eh: %d\n", altura_ArvAVL(MinhaArvore));

    return 0;
}

