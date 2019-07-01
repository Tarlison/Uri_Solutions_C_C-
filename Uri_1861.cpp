#include <iostream>
#include <queue>
#include <string.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct no{
    char nome[11];
    int morto;
    int quant;
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

Nodo *arv_insere_no(Nodo *raiz, string c){
    if (raiz == NULL){
        raiz = (Nodo*)malloc(sizeof(Nodo));
        raiz->dir = raiz->esq = NULL;
        raiz->nome[c.copy(raiz->nome,strlen(c.c_str()),0)] ='\0';
        raiz->quant = 1;
        raiz->morto = 0;
    }
    else if (c < raiz->nome)
        raiz->esq = arv_insere_no(raiz->esq, c);
    else
        raiz->dir = arv_insere_no(raiz->dir, c);
    return raiz;

}

void arv_insere(Arv_bin *arv, string c){
    arv->raiz = arv_insere_no(arv->raiz, c);
}

Nodo *arv_busca_no(Nodo *raiz, string c){
    if (raiz == NULL || raiz->nome == c){
        return raiz;
    }
    if (c < raiz -> nome){
        return arv_busca_no(raiz->esq, c);
    }
    else{
        return arv_busca_no(raiz->dir, c);
    }
}

Nodo *arv_busca(Arv_bin *arv, string k){
    return arv_busca_no(arv->raiz, k);
}

void assassino_quant(string assassino, Arv_bin *arv){
    Nodo *aux = arv_busca(arv, assassino);
    if (aux){
        aux->quant = aux->quant + 1;
    }
    else{
        arv_insere(arv, assassino);
    }
}

void arv_imprime_infixa(Nodo * raiz){
    if(raiz != NULL){
        arv_imprime_infixa(raiz->esq);
        if(raiz->morto != 1){
            cout << raiz->nome;
            cout <<" "<<raiz->quant << endl;
        }
        arv_imprime_infixa(raiz->dir);
    }
}

int main(){
    string assassino, morto;
    queue <string> assassinos, necroterio;
    Arv_bin *arv = arv_cria();
    cin >> assassino >> morto;
    do{
        assassinos.push(assassino);
        necroterio.push(morto);
        cin >> assassino >> morto;
    } while(!cin.eof());
    while(!assassinos.empty()){
        assassino_quant(assassinos.front(),arv);
        assassinos.pop();
    }

    while(!necroterio.empty()){
        Nodo *aux_morto = arv_busca(arv, necroterio.front());
        if (aux_morto != NULL){
            aux_morto->morto = 1;
        }
        necroterio.pop();
    }

    cout << "HALL OF MURDERERS" << endl;
    arv_imprime_infixa(arv->raiz);

    return 0;
}