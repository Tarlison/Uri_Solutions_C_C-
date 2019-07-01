#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

typedef struct no{
    int info;
    struct no *esq;
    struct no *dir;
}Nodo;

typedef struct arv_bin{
    Nodo * raiz;
}Arv_bin;
int aux = 0;
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
void largura(Nodo *raiz){
    queue<Nodo*> fila;
    fila.push(raiz);
    while(!fila.empty()){
        Nodo *p = fila.front();
        fila.pop();
        if(p){
            if (aux != 0){
                printf(" %d",p->info);
            }
            else{
                aux = 1;
                printf("%d",p->info);
            }

            fila.push(p->esq);
            fila.push(p->dir);
        }
    }
}

int main() {
    int c, n, valor, i, cont = 1;
    cin >> c;
    while (c != 0){
        Arv_bin *arv = arv_cria();
        cin >> n;
        for (i = 0; i < n; i++){
            cin >> valor;
            arv_insere(arv,valor);
        }
        printf("Case %d:\n",cont);
        aux = 0;
        largura(arv->raiz);
        cout << endl;
        c--;
    }
    return 0;
}