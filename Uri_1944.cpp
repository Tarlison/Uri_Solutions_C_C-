#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pilha{
    int topo;
    char texto[1000];
}Pilha;

void empilhar(Pilha * dest, char a){
    dest->texto[dest->topo++] = a;
    dest->texto[dest->topo] = '\0';
}

Pilha * criar_pilha(){
    Pilha * n = (Pilha*)malloc(sizeof(Pilha));
    n->topo = 0;
    empilhar(n, 'F');
    empilhar(n, 'A');
    empilhar(n, 'C');
    empilhar(n, 'E');
    return n;
}

void desempilhar(Pilha *destino){
    destino->topo-=8;
    destino->texto[destino->topo] = '\0';
}

int analisar(Pilha * des){
    int t = des->topo;

    if((t >= 8) &&
       (des->texto[t-8] == des->texto[t-1]) &&
       (des->texto[t-7] == des->texto[t-2]) &&
       (des->texto[t-6] == des->texto[t-3]) &&
       (des->texto[t-5] == des->texto[t-4]) ){
        return 1;
    }
    return 0;
}

int main(){
    int casos, total = 0;
    char aux[10];
    Pilha * prova = criar_pilha();

    scanf("%d", &casos);
    setbuf(stdin, NULL);

    for(; casos>0 ;casos--){
        scanf(" %[^\n]s", aux);
        //setbuf(stdin, NULL);

        empilhar(prova, aux[0]);
        empilhar(prova, aux[2]);
        empilhar(prova, aux[4]);
        empilhar(prova, aux[6]);

        //printf("<%s> \n", prova->texto); //apague depois

        if( analisar(prova) ){
            desempilhar(prova);
            total++;
        }

        //printf("<%s> \n", prova->texto); //apague depois

        if(prova->topo == 0){
            empilhar(prova, 'F');
            empilhar(prova, 'A');
            empilhar(prova, 'C');
            empilhar(prova, 'E');
        }
    }
    printf("%d\n", total);

    return 0;
}
