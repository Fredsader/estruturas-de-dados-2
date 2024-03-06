#ifndef ARVOREBINARIA_H_INCLUDED
#define ARVOREBINARIA_H_INCLUDED

// A estrutura do nó da árvore, possui 3 campos: informação inteira, ponteiro esquerdo e ponteiro direito.

struct NO_BST{
   int info;
   struct NO_BST* esq;
   struct NO_BST* dir;
};

// o tipo árvore binária é definido como um ponteiro a uma estrutura nó.
typedef struct NO_BST* ArvBin;

ArvBin* cria_ArvBin();
void libera_ArvBin(ArvBin* raiz);
int insere_ArBin(ArvBin* raiz, int valor);
int remove_ArvBin(ArvBin* raiz, int valor);
int estaVazia_ArvBin(ArvBin* raiz);
int altura_ArvBin(ArvBin* raiz);
int totalNO_ArvBin(ArvBin* raiz);
int consulta_ArvBin(ArvBin* raiz, int valor);
void emOrdem_ArvBin(ArvBin* raiz);
void preOrdem_ArvBin(ArvBin* raiz);
void posOrdem_ArvBin(ArvBin* raiz);
#endif // ARVOREBINARIA_H_INCLUDED
