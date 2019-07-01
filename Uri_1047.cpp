#include<stdio.h>

int main(){
    int h_inicio,h_final,h_total,m_inicio,m_final,m_total;
    scanf ("%d %d %d %d",&h_inicio, &m_inicio,&h_final,&m_final);
    h_total = h_final - h_inicio;
    m_total = m_final - m_inicio;
    if (h_total < 0 ){
        h_total = 24 + (h_total);
    }
    if (m_total < 0){
        m_total = 60 + m_total;
        h_total -= 1;
    }
    if (h_inicio == h_final & m_inicio == m_final){
        printf("O JOGO DUROU 24 HORA(S) E 0 MINUTO(S)\n");
    }
    else {
        printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", h_total, m_total);
    }
    return 0;
}