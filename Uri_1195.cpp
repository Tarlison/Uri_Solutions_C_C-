#include <iostream>
#include <stdio.h>
using namespace std;

typedef struct no{
    int info;
    struct no *esq;
    struct no *dir;
}Nodo;

typedef struct arv_bin{
    Nodo * raiz;
}Arv_bin;

Arv_bin *arv_cria(){
    Arv_bin * arv = (Arv_bin *) malloc(sizeof(Arv_bin));
    arv->raiz = NULL;
    return arv;
}

Nodo *arv_insere_no(Nodo *raiz, int c){
    if (raiz == NULL){
        raiz = (Nodo*)malloc(sizeof(Nodo));
        raiz->dir = raiz->esq = NULL;
        raiz->info = c;
    }
    else if (c < raiz->info)
        raiz->esq = arv_insere_no(raiz->esq, c);
    else
        raiz->dir = arv_insere_no(raiz->dir, c);
    return raiz;
}

void arv_insere(Arv_bin *arv, int c){
    arv->raiz = arv_insere_no(arv->raiz, c);
}

void nodo_free(Nodo *nodo){
    if(nodo != NULL){
        nodo_free(nodo->esq);
        nodo_free(nodo->dir);
        free(nodo);
    }
}

void arv_free(Arv_bin *arv){
    nodo_free(arv->raiz);
    free(arv);
}


void arv_imprime_pre_ordem(Nodo * raiz){
    if(raiz != NULL){
        printf(" %d", raiz->info);
        arv_imprime_pre_ordem(raiz->esq);
        arv_imprime_pre_ordem(raiz->dir);
    }
}

void arv_imprime_infixa(Nodo * raiz){
    if(raiz != NULL){
        arv_imprime_infixa(raiz->esq);
        printf(" %d", raiz->info);
        arv_imprime_infixa(raiz->dir);
    }
}

void arv_imprime_pos_ordem(Nodo * raiz){
    if(raiz != NULL){
        arv_imprime_pos_ordem(raiz->esq);
        arv_imprime_pos_ordem(raiz->dir);
        printf(" %d", raiz->info);
    }
}


int main() {
    int c, n, i, valor, cont = 1;
    scanf("%d",&c);
    while( c != 0){
        Arv_bin *arv = arv_cria();
        scanf("%d",&n);
        for(i = 0; i < n; i++){
            scanf(" %d", &valor);
            arv_insere(arv, valor);
        }
        printf("Case %d:\n", cont);
        printf("Pre.:");
        arv_imprime_pre_ordem(arv->raiz);
        printf("\n");
        printf("In..:");
        arv_imprime_infixa(arv->raiz);
        printf("\n");
        printf("Post:");
        arv_imprime_pos_ordem(arv->raiz);
        printf("\n\n");
        arv_free(arv);
        cont++;
        c--;
    }
    return 0;
}