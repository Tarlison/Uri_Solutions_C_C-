#include<stdio.h>
int main(){
    int s,t,f,horario;
    scanf("%d %d %d",&s,&t,&f);
    horario = s+t+f;
    if (s == 0){
        s = 24;
        horario = s+t+f;
    }
    if (horario >= 24){
        horario = horario - 24;
        printf("%d\n",horario);
    }
    else{
        printf("%d\n",horario);
    }
    return 0;
}