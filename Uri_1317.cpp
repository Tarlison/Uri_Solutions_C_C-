#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

class Graph{
    int V; // Quantidade de Vertices
    int quant_status; // Quantidade de Status
    list<int> *adj;
    list<string> *status; // lista com todos os status

    void DFSUtil(int v, bool visited[], int t1, int t2, string a1, string a2, string a3);
    public:
    Graph(int V);
    void addStatus(string a1);
    void addEdge(int v1, int v2);
    void DFS(int v, int t1, int t2, string a1, string a2, string a3);
    void printStatus(int v);
};

Graph::Graph(int V){
    this->V = V;
    quant_status = 0; // Inicia com 0 status
    adj = new list<int>[V];
    status = new list<string>[V];
}

void Graph::addEdge(int v1, int v2){
    adj[v1].push_back(v2);
}

void Graph::addStatus(string a1){
    quant_status++; // Adiciona um status
    for(int i = 1; i < V; i++){
    status[i].push_back(a1); //Todo mundo inicia com todos os status em A1, que é quando quant_status quantidade de mensagens é menor que T1
}
}

//Função que printa todos os status de uma pessoa
void Graph::printStatus(int v){
    for(int it = 0; it < quant_status; ++it){
        cout << status[v].front() << " ";
        status[v].pop_front();
    }
}

void Graph::DFSUtil(int v, bool visited[], int t1, int t2, string a1, string a2, string a3){
    visited[v] = true;

    // Verifica quanta mensagens aquela pessoa enviou
    if(adj[v].size() >= t1 && adj[v].size() < t2){
    //ele remove o A1 que tinha anteriormente e coloca o A2 no lugar e assim ele faz na proxima condição
        status[v].pop_back();
        status[v].push_back(a2);
    } 
    else if(adj[v].size() >= t2){
        status[v].pop_back();
        status[v].push_back(a3);
    }

    list<int>::iterator it;
    for(it = adj[v].begin(); it != adj[v].end(); ++it){
        if(!visited[*it]){
            DFSUtil(*it, visited, t1, t2, a1, a2, a3);
        }
    }
}

void Graph::DFS(int v, int t1, int t2, string a1, string a2, string a3){
    bool *visited = new bool[V];
    for(int i = 1; i < V; i++){
        visited[i] = false;
    }
    DFSUtil(v, visited, t1, t2, a1, a2, a3);
}

int main(){
    int n, fi, p, t1, t2;
    string a1, a2, a3, nome;

    cin >> n;

    while(n != 0){
        n++;
        Graph g(n);

        //FOR que adiciona todas as pessoas que o indice i tem contato
        for(int i = 1; i < n; i++){
            fi = 1;
            while(fi){
                cin >> fi;
                if(fi != 0){
                    g.addEdge(i, fi);
            }
        }
    }

    //WHILE que adiciona todos os STATUS e acrescenda A1 em todos
        p = 1;
        while(p){
            cin >> p;
            if(p != 0){
                cin >> t1 >> t2 >> a1 >> a2 >> a3;
                g.addStatus(a1);
                g.DFS(p, t1, t2, a1, a2, a3);
            }
        }

        //FOR que Printa todo os status
        for(int i = 1; i < n; i++){
            cin >> nome;
            cout << nome << ": ";
            g.printStatus(i);
            cout << endl;
        }
        cin >> n;
            
    }


}