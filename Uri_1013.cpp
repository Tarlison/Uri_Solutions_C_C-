#include<bits/stdc++.h>
using namespace std;

int main(){
    int x,y,z,maiorab,maior;
    scanf("%d %d %d", &x, &y, &z);
    maiorab = (x+y+abs(x-y))/2;
    maior = (maiorab+z+abs(maiorab-z))/2;
    printf("%d eh o maior\n",maior);
    return 0;
}