#include <bits/stdc++.h>
using namespace std;

typedef struct SegTree{
    int *input;
    int *zeros;
    int *negativos;
}Seg;


void build(int *input,Seg *segtree, int low, int high, int position){
    if(low == high){
        if(input[low] == 0){
            segtree->zeros[position] = 1;
            segtree->negativos[position] = 0;
        }
        else if (input[low] < 0){
            segtree->zeros[position] = 0;
            segtree->negativos[position] = 1;
        }
        else{
            segtree->zeros[position] = 0;
            segtree->negativos[position] = 0;
        }
        return;
    }

    int mid = (low+high)/2;
    build(input, segtree, low, mid, 2*position+1); // 1
    build(input, segtree, mid+1, high, 2*position+2); // 2
    segtree->negativos[position] = segtree->negativos[2*position+1] + segtree->negativos[2*position+2];
    segtree->zeros[position] = max(segtree->zeros[2*position+1],segtree->zeros[2*position+2]);


}

int search(int *arv, int qlow, int qhigh, int low, int high, int position){
    if (qlow <= low && high <= qhigh){ //total overleap
        return arv[position];
    }
    if (qlow > high || qhigh < low){ //no overleap
        return 0;
    }
    int mid = (low+high)/2;
    int left = search(arv,qlow,qhigh,low,mid,2*position+1);
    int right = search(arv,qlow,qhigh,mid+1,high,2*position+2);
    return left + right;
}

void atualizaArv(Seg *segtree, int pos_input, int l, int h, int valor_para_troca ,int pos_arv){
    if (valor_para_troca > 0 ){
        segtree->negativos[pos_arv] -= segtree->input[pos_input] < 0;
        segtree->zeros[pos_arv] -= segtree->input[pos_input] == 0;
    }

    else if (valor_para_troca < 0){
        segtree->negativos[pos_arv] += segtree->input[pos_input] >= 0 ;
        segtree->zeros[pos_arv] -= segtree->input[pos_input] == 0;
    }

    else{
        segtree->negativos[pos_arv] -= segtree->input[pos_input] < 0;
        segtree->zeros[pos_arv] += segtree->input[pos_input] != 0;
    }

    if (h == l){
        segtree->input[pos_input] = valor_para_troca;
        return;
    }

    int mid = (l + h)/2;

    if (pos_input <= mid){
        atualizaArv(segtree, pos_input, l, mid, valor_para_troca, 2*pos_arv+1);
    }

    else{
        atualizaArv(segtree, pos_input, mid+1, h, valor_para_troca, 2*pos_arv+2);
    }

    segtree->negativos[pos_arv] = segtree->negativos[2*pos_arv+1] + segtree->negativos[2*pos_arv+2];
    segtree->zeros[pos_arv] = max(segtree->zeros[2*pos_arv+1],segtree->zeros[2*pos_arv+2]);

}


int main() {
    int n_elementos, n_rodadas, posicao, valor, aux = 0, is_zero, is_negativo;
    char comando;

    Seg *seg = (Seg*)malloc(sizeof(Seg));

    while(cin >> n_elementos >> n_rodadas){

        seg->input = new int[100000];
        seg->zeros = new int[400000];
        seg->negativos = new int[400000];
        char *saidas = (char*)malloc(100000 * sizeof(char));

        for (int i = 0; i < n_elementos; i++){
            cin >> seg->input[i];
        }
        build(seg->input, seg, 0, n_elementos-1, 0);

        while(n_rodadas > 0){
            cin >> comando;
            cin >> posicao >> valor;
            if (comando == 'C'){
                atualizaArv(seg, posicao-1, 0, n_elementos-1, valor, 0);
            }
            else{
                is_zero = search(seg->zeros, posicao-1, valor-1, 0, n_elementos-1, 0);
                if (is_zero == 0){
                    is_negativo = search(seg->negativos, posicao-1, valor-1, 0, n_elementos-1, 0);
                    if (is_negativo % 2 == 0){
                        saidas[aux] = '+';
                        aux++;
                    }
                    else {
                        saidas[aux] = '-';
                        aux++;
                    }
                }
                else{
                    saidas[aux] = '0';
                    aux++;
                }
            }
            n_rodadas--;

        }

        for (int j = 0; j < aux; j++){
            cout << saidas[j];
        }
        cout << endl;
        aux = 0;
    }

    return 0;
}