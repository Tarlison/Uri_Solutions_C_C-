#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
typedef struct no{
    char info;
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

Nodo *arv_insere_no(Nodo *raiz, char c){
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

void arv_insere(Arv_bin *arv, char c){
    arv->raiz = arv_insere_no(arv->raiz, c);
}

void arv_imprime_pre_ordem(Nodo * raiz, int *cont_print){
    if(raiz != NULL){

        if (*cont_print != 0){
            printf(" %c", raiz->info);
        }else{
            *cont_print = 1;
            printf("%c",raiz->info);
        }

        arv_imprime_pre_ordem(raiz->esq, cont_print);
        arv_imprime_pre_ordem(raiz->dir, cont_print);
    }
}

void arv_imprime_infixa(Nodo * raiz, int *cont_print){
    if(raiz != NULL){
        arv_imprime_infixa(raiz->esq, cont_print);

        if (*cont_print != 0){
            printf(" %c", raiz->info);
        }else{
            *cont_print = 1;
            printf("%c",raiz->info);
        }

        arv_imprime_infixa(raiz->dir, cont_print);
    }
}

void arv_imprime_pos_ordem(Nodo * raiz, int *cont_print){
    if(raiz != NULL){
        arv_imprime_pos_ordem(raiz->esq, cont_print);
        arv_imprime_pos_ordem(raiz->dir, cont_print);

        if (*cont_print != 0){
            printf(" %c", raiz->info);
        }else{
            *cont_print = 1;
            printf("%c",raiz->info);
        }

    }
}

Nodo *arv_busca_no(Nodo *raiz, char c){
    if (raiz == NULL || raiz->info == c){
        return raiz;
    }
    if (c < raiz -> info){
        return arv_busca_no(raiz->esq, c);
    }
    else{
        return arv_busca_no(raiz->dir, c);
    }
}

Nodo *arv_busca(Arv_bin *arv, char k){
    return arv_busca_no(arv->raiz, k);
}

int main() {
    string input1;
    char input2;
    int cont_print = 0; // Contador para ajustar o print para o URI

    Arv_bin *arv = arv_cria();

    while(cin >> input1){

        if (input1 == "I"){
            cin >> input2;
            arv_insere(arv, input2);
        }else if (input1 == "INFIXA"){
            cont_print = 0;
            arv_imprime_infixa(arv->raiz, &cont_print);
            cout << endl;
        } else if (input1 == "PREFIXA"){
            cont_print = 0;
            arv_imprime_pre_ordem(arv->raiz, &cont_print);
            cout << endl;
        } else if (input1 == "POSFIXA"){
            cont_print = 0;
            arv_imprime_pos_ordem(arv->raiz, &cont_print);
            cout << endl;
        } else if (input1 == "P"){
            cin >> input2;
            arv_busca(arv, input2) == NULL ? printf("%c nao existe\n",input2) : printf("%c existe\n",input2);
        }
    }
    return 0;
}