#include <bits/stdc++.h>
using namespace std;

class Grafo{
private:
    int N_vertices;
    vector<vector<int>> v;
    vector<int> visitado;
    bool ciclo;
public:
    Grafo(int N_vertices);
    void DFS(int v1);
    void DFSUtil(int v1);
    void addEdge(int v1, int w1);
    void setVetores();
    bool getCiclo();
};

Grafo::Grafo(int N_vertices){
    this->N_vertices = N_vertices;
    v.assign(N_vertices,vector<int>());
}

void Grafo::setVetores(){
    visitado.clear();
    v.clear();
}

void Grafo::DFS(int v1){
    //cout << "Dentro do dfs" << endl;
    ciclo = false;

    visitado.assign(N_vertices,0); //deixa todos como nao visitados;

    for(int i = 0; i < N_vertices; i++){
      //  cout << "dentro do for do DFS" << endl;
        if(visitado[i] == 0){
       //     cout << "dentro do if do dfs" << endl;
            DFSUtil(i);
        }
        if(ciclo == 1){
            break;
        }
    }
}

void Grafo::DFSUtil(int v1){
    //cout << "dfsutil" << endl;
    visitado[v1] = 1;

    if(ciclo == 1){
        return;
    }

    for(int i = 0; i < v[v1].size(); i++){
        //cout << "for do dfsUTIL" << endl;
        if(visitado[v[v1][i]] == 1){
            //cout << "if do for do dfsUtil" << endl;
            ciclo = true;
            return;
        }
        else if(visitado[v[v1][i]] == 0){
          //  cout << "else if da pilha recursiva" << endl;
            DFSUtil(v[v1][i]);
        }
    }
    visitado[v1] = 2;
}

void Grafo::addEdge(int v1,int w1){
    v[v1].push_back(w1);
}

bool Grafo::getCiclo(){
    return this->ciclo;
}

int main(){
    int casos, n_doc, n_depe, docA_depe, docB_depe;
    
    scanf("%d", &casos);

    while (casos--){
        scanf("%d %d", &n_doc, &n_depe);
        Grafo cartas(n_doc);
        for (int i = 0; i < n_depe; i++){
            scanf("%d %d", &docA_depe, &docB_depe);
          //  cout << "arestas" << endl;
            cartas.addEdge(docA_depe-1, docB_depe-1);
          //  cout << "adicionadas" << endl;
        }
        //cout << "DFS:" << endl;
        cartas.DFS(0);
        //cout << "Depois do dfs" << endl;
        if(cartas.getCiclo() == 1){
            printf("SIM\n");
        }
        else{
            printf("NAO\n");
        }

        cartas.setVetores();
        

    }
    
}