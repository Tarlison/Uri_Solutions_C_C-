#include <stdlib.h>
#include <stdio.h>

typedef struct pilha{
    int top;
    int vetor[50];

}Pilha;

void push(Pilha *p, int v){
    p->vetor[p->top] = v;
    p->top++;
}

void pop(Pilha *p, int *v){
    p->top--;
    *v = p->vetor[p->top];
}

void goToBase(Pilha *p,int v){
   int i, aux;
   for (i = p->top; i > 0; i--){
        aux = p->vetor[i];
        p->vetor[i] = p->vetor[i-1];
        p->vetor[i-1] = aux;
   }

}

int main(){
    int n, i,valor,valores;
    scanf("%d",&n);
    Pilha *p = (Pilha*)malloc(n*sizeof(Pilha));
    p->top = 0;

    while (n != 0){
        for (i = n; i > 0; i--){
            push(p,i);
        }
        p->top--;
        if(n > 1){
            printf("Discarded cards: ");
            while (p->top >= 1 ){
                valor = p->vetor[p->top];
                if(p->top > 1){
                    printf("%d, ",valor);
                }
                else{
                    printf("%d\n", valor);
                }
                pop(p,&valor);
                goToBase(p, p->vetor[p->top]);

            }
            printf("Remaining card: %d\n", p->vetor[p->top]);
        }
        else{
            printf("Discarded cards:\n");
            printf("Remaining card: %d\n", p->vetor[p->top]);

        }
        scanf("%d",&n);
    }
    return 0;
}