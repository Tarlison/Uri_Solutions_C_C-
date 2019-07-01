#include <stdio.h>
#include <stdlib.h>

int ordenarContar(int *vetor, int tamanho){
    int i, j, min, aux,trocas = 0;
    for (i = 0; i < (tamanho - 1); i++) {
        min = i;
        for (j = i+1; j < tamanho; j++) {
            if (vetor[j] < vetor[min]) {
                min = j;
            }
        }
        if (i != min) {
            aux = vetor[i];
            vetor[i] = vetor[min];
            vetor[min] = aux;
            trocas = trocas + 1;

        }
    }

    return trocas;
}

int main(){
    int quantValores, quantTrocas, i, instancias, cont = 0;
    scanf("%d",&instancias);
    
    while(cont < instancias){
        scanf("%d",&quantValores);
        int *valores = (int*)malloc(quantValores * sizeof(int));

        for (i = 0; i < quantValores; ++i){
            scanf("%d", &valores[i]);
        }

        quantTrocas = ordenarContar(valores,quantValores);
        printf("%d\n",quantTrocas);
        cont++;
    }

}