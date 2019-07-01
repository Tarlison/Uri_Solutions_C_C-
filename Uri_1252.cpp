#include <stdio.h>
#include <stdlib.h>

/*
    Componentes : Tarlison Sander
     e Luigi Muller
     algoritmo do merge sort alterado pra trabalhar com struct do https://pt.wikipedia.org/wiki/Merge_sort
*/

typedef struct Valor{

	int n;

	int nMod;

}valor;

void merge(valor *vetor, int comeco, int meio, int fim) {
    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    valor *vetAux = (valor*)malloc(tam * sizeof(valor));

    while(com1 <= meio && com2 <= fim)
    {

        if(vetor[com1].nMod != vetor[com2].nMod)
        {
            
            if(vetor[com1].nMod < vetor[com2].nMod )
            {
                vetAux[comAux] = vetor[com1];
                com1++;
            }
            else
            {
                vetAux[comAux] = vetor[com2];
                com2++;
            }
        }

        else if(vetor[com1].nMod == vetor[com2].nMod && (vetor[com1].n %2 == 0 && vetor[com2].n %2 != 0) || (vetor[com1].n %2 != 0 && vetor[com2].n % 2 == 0))
        {
            if(vetor[com1].n %2 != 0)
            {
                vetAux[comAux] = vetor[com1];
                com1++;
            }
            else
            {
                vetAux[comAux] = vetor[com2];
                com2++;
            }
        }

        else if(vetor[com1].nMod == vetor[com2].nMod && vetor[com1].n %2 != 0 && vetor[com2].n %2 !=0)
        {
            if(vetor[com1].n > vetor[com2].n)
            {
                vetAux[comAux] = vetor[com1];
                com1++;
            }
            else
            {
                vetAux[comAux] = vetor[com2];
                com2++;
            }
        }
        else if(vetor[com1].nMod == vetor[com2].nMod && vetor[com1].n %2 == 0 && vetor[com2].n %2 ==0)
        {
            if(vetor[com1].n < vetor[com2].n )
            {
                vetAux[comAux] = vetor[com1];
                com1++;
            }
            else
            {
                vetAux[comAux] = vetor[com2];
                com2++;
            }
        }

        else
        {
            vetAux[comAux] = vetor[com2];
            com2++;
        }

        comAux++;
    }

    while(com1 <= meio){  //Caso ainda haja elementos na primeira metade
        vetAux[comAux] = vetor[com1];
        comAux++;
        com1++;
    }

    while(com2 <= fim) {   //Caso ainda haja elementos na segunda metade
        vetAux[comAux] = vetor[com2];
        comAux++;
        com2++;
    }

    for(comAux = comeco; comAux <= fim; comAux++){    //Move os elementos de volta para o vetor original
        vetor[comAux] = vetAux[comAux-comeco];
    }
    
    free(vetAux);
}

void mergeSort(valor vetor[], int comeco, int fim){
    if (comeco < fim) {
        int meio = (fim+comeco)/2;

        mergeSort(vetor, comeco, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, comeco, meio, fim);
    }
}

int main(){
	int quant, mod, aux,i = 0;

	scanf("%d %d", &quant, &mod);

	while(quant != 0 && mod != 0){
		
		valor *valores = (valor*) malloc(quant * sizeof(valor));

		for (i = 0; i < quant; i++){
			scanf("%d", &aux);
			valores[i].n = aux;
			valores[i].nMod = aux % mod;
		}

		mergeSort(valores,0,quant-1);
		
		printf("%d %d\n",quant,mod);

		for (i = 0; i < quant; i++){
			printf("%d\n", valores[i].n);
		}
		
		scanf("%d %d", &quant, &mod);
	}

	printf("0 0\n");
	return 0;
}