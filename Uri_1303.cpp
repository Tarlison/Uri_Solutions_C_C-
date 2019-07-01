#include <stdio.h>
#include <stdlib.h>

typedef struct Time{
       int inscricao;
       int pontos;
       int pontosFeitos;
       int pontosLevados;
}time;

int ordenarTimes(const void *a, const void *b); //função feita com ajuda do Gustavo Mendonça -> https://github.com/gmendonca

int main(){
    int jogos, numEquip1, pts1, numEquip2, pts2;
    int instacias = 0, n, i;
    scanf("%d", &n);
    if (n != 0){
      do{
          time *equipes = (time*) malloc(n * sizeof(time));
          jogos = n*(n-1)/2;
          for(i = 0; i < n; i++){
                equipes[i].inscricao = 0;
                equipes[i].pontos = 0;
                equipes[i].pontosFeitos = 0;
                equipes[i].pontosLevados = 0;
          }
          for(i = 0; i < jogos; i++){
               scanf("%d %d %d %d", &numEquip1, &pts1, &numEquip2, &pts2);
               if(equipes[numEquip1-1].inscricao == 0){
                  equipes[numEquip1-1].inscricao = numEquip1;
               }

               if(equipes[numEquip2-1].inscricao == 0) {
                  equipes[numEquip2-1].inscricao = numEquip2;
               }

               equipes[numEquip1-1].pontosFeitos += pts1;
               equipes[numEquip1-1].pontosLevados += pts2;
               equipes[numEquip2-1].pontosFeitos += pts2;
               equipes[numEquip2-1].pontosLevados += pts1;


               if(pts1 - pts2 > 0){
                    equipes[numEquip1-1].pontos += 2;
                    equipes[numEquip2-1].pontos += 1;
               }
               else{
                     equipes[numEquip2-1].pontos += 2;
                     equipes[numEquip1-1].pontos += 1;
               }
          }
          instacias = instacias + 1;
          qsort(equipes,n,sizeof(time),ordenarTimes);
          printf("Instancia %d\n",instacias);
          for(i = 0; i < n-1; i++){
                printf("%d ",equipes[i].inscricao);
          }
          printf("%d\n",equipes[i].inscricao);
          scanf("%d", &n);
          if(n!=0){ //Unico jeito que consegui corrigir o problema do \n a mais
            printf("\n");
          }

      }while(n != 0);
    }
    return 0;
}
int ordenarTimes(const void *a, const void *b){

    time *equipeA = (time *)a;

    time *equipeB = (time *)b;

    if(equipeB->pontos != equipeA->pontos){
      return equipeB->pontos - equipeA->pontos;
    }

    if(equipeB->pontosLevados == 0){
      equipeB->pontosLevados = 1;
    }
    if(equipeA->pontosLevados == 0){
      equipeA->pontosLevados = 1;
    }
    if((float)equipeB->pontosFeitos/ (float)equipeB->pontosLevados != (float)equipeA->pontosFeitos/(float)equipeA->pontosLevados){

        if((float)equipeB->pontosFeitos/(float)equipeB->pontosLevados - (float)equipeA->pontosFeitos/(float)equipeA->pontosLevados > 0){
            return 1;
        }
        else{
            return -1;
        }
    }
    if((float)equipeB->pontosFeitos != (float)equipeA->pontosFeitos)
        return equipeB->pontosFeitos - equipeA->pontosFeitos;
    return equipeB->inscricao - equipeA->inscricao;
}
