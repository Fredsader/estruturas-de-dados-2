#ifndef ARVOREBINARIA_H_INCLUDED
#define ARVOREBINARIA_H_INCLUDED

// o tipo �rvore bin�ria � definido como um ponteiro a uma estrutura n�.
typedef struct NO* ArvBin;

struct NO* busca_ArvBin(ArvBin raiz, int valor);

ArvBin* cria_ArvBin();
void libera_ArvBin(ArvBin* raiz);
int insere_ArBin(ArvBin* raiz, int valor);
int remove_ArvBin(ArvBin* raiz, int valor);
int estaVazia_ArvBin(ArvBin* raiz);
int altura_ArvBin(ArvBin* raiz);
int totalNO_ArvBin(ArvBin* raiz);
int consulta_ArvBin(ArvBin* raiz, int valor);
void emOrdem_ArvBin(ArvBin* raiz);
#endif // ARVOREBINARIA_H_INCLUDED
