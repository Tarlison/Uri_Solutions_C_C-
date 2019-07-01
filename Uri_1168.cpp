#include <stdio.h>
#include <string.h>
int main(){
    int n,i = 0,d,led = 0;
    char v[1110];
    scanf("%d",&n);
    while (n != 0){
        scanf("%s",&v);
        d=strlen(v);
        for (i = 0; i < d; i++){
            if (v[i] == '1') led+= 2;
            if (v[i] == '2' || v[i] == '5' || v[i] == '3') led+= 5;
            if (v[i] == '4') led+= 4;
            if (v[i] == '6' || v[i] == '0' || v[i] == '9') led+= 6;
            if (v[i] == '7') led+= 3;
            if (v[i] == '8') led+= 7;
        }
        printf("%d leds\n",led);
        led = 0;
        n-= 1;
    }
    return 0;
}