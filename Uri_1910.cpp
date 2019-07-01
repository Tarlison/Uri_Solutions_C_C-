#include<bits/stdc++.h>
#include<queue>
#define MAX 100000
using namespace std;

int O, D, K, canal_proibido;

class Grafo{

    int N_vertices;

    bool ehvalido(int indice, int c);


public:
    int canais[MAX+5];

    int amount[MAX+5];

    Grafo(int N_vertices);

    int BFSUtil(int origem, int destino);

};

Grafo::Grafo(int N_vertices) {
    this->N_vertices = N_vertices;
}

bool Grafo::ehvalido(int indice, int c){
    if(indice <= MAX && indice >= 1 && canais[indice] == 1 && c < amount[indice] ) {
        amount[indice] = c;
        return true;
    }
    return false;
}

int Grafo::BFSUtil(int origem, int destino) {
  queue< pair<int,int> > q;
  pair <int,int> s;
  s.first = origem;
  s.second = 0;
  q.push(s);
  amount[s.first] = 0;
  while(!q.empty()) {
    pair <int,int> a = q.front();
    q.pop();
    if(a.first == destino){
        return a.second;
    }

    if(ehvalido(a.first + 1,a.second + 1)){
        q.push(make_pair(a.first + 1,a.second + 1));
    } 
    if(ehvalido(a.first - 1,a.second + 1)){
        q.push(make_pair(a.first - 1,a.second + 1));
    } 
    if(ehvalido(a.first * 3,a.second + 1)){
        q.push(make_pair(a.first * 3,a.second + 1));
    } 
    if(ehvalido(a.first * 2,a.second + 1)){
        q.push(make_pair(a.first * 2,a.second + 1));
    } 
    if(a.first%2 == 0){
        if(ehvalido(a.first/2,a.second + 1)){
            q.push(make_pair(a.first/2,a.second + 1));
        } 
    } 
  }
  return -1;
}

int main(){
    
    while (scanf("%d %d %d", &O, &D, &K)){
        if (O == 0 && D == 0 && K == 0)
            return 0;

        else{
            Grafo controle(MAX);
            for(int i = 0;i <= MAX; i++) {
                controle.canais[i] = 1;
                controle.amount[i] = INT_MAX;
            }

            for(int i = 0; i < K; i++){
                scanf("%d", &canal_proibido);
                controle.canais[canal_proibido] = 0;
            }
            cout << controle.BFSUtil(O,D) << endl;
        }
    }

    return 0;
}