#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Teste_Arvore_Binaria_Backes/Teste_Arvore_Binaria/ArvoreBinaria.c"

using namespace std;

int main() {
    setlocale(LC_ALL, "");

    ArvBin* minhaArvore = cria_ArvBin();

    // Inserindo alguns valores na �rvore
    insere_ArBin(minhaArvore, 10);
    insere_ArBin(minhaArvore, 5);
    insere_ArBin(minhaArvore, 15);
    insere_ArBin(minhaArvore, 7);
    insere_ArBin(minhaArvore, 12);

    // Realizando uma busca
    int valorBusca;
    printf("Digite o valor para buscar: ");
    scanf("%d", &valorBusca);
    struct NO* resultadoBusca = busca_ArvBin(*minhaArvore, valorBusca);

    // Verificando o resultado
    if (resultadoBusca != NULL)
        printf("Valor %d encontrado na �rvore!\n", valorBusca);
    else
        printf("Valor %d n�o encontrado na �rvore.\n", valorBusca);
    // Liberando a �rvore
    libera_ArvBin(minhaArvore);

    return 0;
}
