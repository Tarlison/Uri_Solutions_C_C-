#include <iostream>
#include <list>
using namespace std;

int cops = 0;
int gambiarra1 = 0;
int gambiarra2 = 0;

class Grafo{
private:
    int N_vertices;
    bool visitado[6][6];
    
public:
    int matriz[6][6];
    Grafo(int N_vertices);
    void DFS(int v);
    void DFSUtil(int i, int j, bool visitado[6][6]);
};

Grafo::Grafo(int N_vertices){
    this->N_vertices = N_vertices;
}

void Grafo::DFSUtil(int i,int j, bool visitado[6][6]){
    
    visitado[i][j] = true;

    if(i == 4 && j == 4){
        //cout << "entrei??" << endl;
        cops = 1;
        return;                         
    }
    //cout << "i :" << i << " j:" << j << endl;
    if(matriz[i][j+1] == 0 && visitado[i][j+1] == false && ((i >= 0  &&  i <= 4) && (j+1 >= 0 && j+1 <= 4)) ){ //direita
        //cout << "direita" << endl;
        DFSUtil(i,j+1, visitado);
    }
    if(matriz[i][j-1] == 0 && visitado[i][j-1] == false && ((i >= 0  &&  i <= 4) && (j-1 >= 0 && j-1 <= 4)) ){ //esquerda
        //cout << "esquerda" << endl;
        DFSUtil(i,j-1, visitado);
    }
    if(matriz[i+1][j] == 0 && visitado[i+1][j] == false && ((i+1 >= 0  &&  i+1 <= 4) && (j >= 0 && j <= 4))) { //para baixo
        //cout << "pra baixo" << endl;
        DFSUtil(i+1,j, visitado);
    }
    if(matriz[i-1][j] == 0 && visitado[i-1][j] == false && ((i-1 >= 0  &&  i-1 <= 4) && (j >= 0 && j <= 4))){ //para cima
        //cout << "pra cima" << endl;
        DFSUtil(i-1,j, visitado);
    }
    
}

void Grafo::DFS(int v){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            visitado[i][j] = false;
        }
    }
    DFSUtil(v,v,visitado);

}

int main(){
    int casosDeTeste, i, j;
    Grafo lab(40);
    cin >> casosDeTeste;
    
    while(casosDeTeste--){
        
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                scanf("%d", &lab.matriz[i][j]);
            }
        }

        if(lab.matriz[4][4] == 1 || lab.matriz[0][0] == 1){
            cout << "ROBBERS" << endl;
        }
        else{
            lab.DFS(0);
            if(cops == 1){
                cout << "COPS" << endl;
            }
            else{
                cout << "ROBBERS" << endl;
            }
        }
        cops = 0;
    }
    return 0;
}