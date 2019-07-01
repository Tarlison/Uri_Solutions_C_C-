#include <stdio.h>
#include <stdlib.h>
void organizar(int *vetor, int x){
  int i, j,temp;
  for(i = 0; i < x; i++){
    for(j = i+1; j < x; j++){
        if(vetor[i] < vetor[j]){
            temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
        }
    }
  }
}
int comparar(int *vetor1, int *vetor2, int x){
    int i, iguais = 0;
    for(i = 0; i < x; i++){
        if (vetor1[i] == vetor2[i]){
            iguais += 1;
        }
    }
    return iguais;

}
int main(){
    int notas[1000],n, i,quant_alunos, nao_trocaram, notas2[1000];
    scanf("%d", &n);
    while(n > 0){
        scanf("%d", &quant_alunos);
        for (i = 0; i < quant_alunos; i++){
            scanf("%d",&notas[i]);
            notas2[i] = notas[i];
        }
        organizar(notas,quant_alunos);
        nao_trocaram = comparar(notas,notas2,quant_alunos);
        printf("%d\n", nao_trocaram);
        n-=1;
    }

    return 0;
}