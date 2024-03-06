#ifndef ARVOREBAVL_H_INCLUDED
#define ARVOREAVL_H_INCLUDED

// o tipo árvore binária é definido como um ponteiro a uma estrutura nó.
struct NO{
   int info;
   int alt;
   struct NO* esq;
   struct NO* dir;
};


typedef struct NO* ArvAVL;

ArvAVL* cria_ArvAVL();
void libera_ArvAVL(ArvAVL* raiz);
int insere_ArvAVL(ArvAVL* raiz, int valor);
int remove_ArvAVL(ArvAVL* raiz, int valor);
int estaVazia_ArvAVL(ArvAVL* raiz);
int altura_ArvAVL(ArvAVL* raiz);
int alt_NO(struct NO* no);
int totalNO_ArvAVL(ArvAVL* raiz);
int consulta_ArvAVL(ArvAVL* raiz, int valor);
void emOrdem_ArvAVL(ArvAVL* raiz);

void preOrdem_ArvAVL(ArvAVL* raiz);
void posOrdem_ArvAVL(ArvAVL* raiz);
#endif // ARVOREBINARIA_H_INCLUDED
