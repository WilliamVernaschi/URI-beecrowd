#include <iostream>
 
using namespace std;
 
int main() {
    int n; cin >> n;
    int dados[n];
    for(int j = 0; j < n; j++){
        cin >> dados[j];
    }
    int somas[7] = {0};
    
    int menor_somas = 2147483647;
    for(int j = 1; j <= 6; j++){
        for(int i = 0; i < n; i++){
            int qtd_movimentos = 0;
            if(dados[i] + j == 7) qtd_movimentos = 2;
            else if(dados[i] != j) qtd_movimentos = 1;
            somas[j] += qtd_movimentos;
        }
        if(somas[j] < menor_somas) menor_somas = somas[j];
    }
    
    cout << menor_somas << endl;
 
    return 0;
}