#include <iostream>
#include <cmath>

using namespace std;

struct pedra{
  char tipo;
  int dis_margem;
};

bool foiusada[105];
int d;


int main(){
  int n; cin >> n;
  for(int k = 0; k < n; k++){
    int n_pedras; cin >> n_pedras; cin >> d;


    pedra pedras[105];


    for(int i = 1; i <= n_pedras; i++){
      string p; cin >> p;
      int tipo = p[0];
      int dis_margem = stoi(p.substr(2, p.size() - 2));
      pedras[i].tipo = tipo;
      pedras[i].dis_margem = dis_margem;
    }

    int max_pulo = 0;
    int dist_percorrida = 0;
    int cont_pedras_peq = -1;

    pedras[0].tipo = 'B';
    pedras[0].dis_margem = 0;

    pedras[n_pedras+1].tipo = 'B';
    pedras[n_pedras+1].dis_margem = d;




    for(int i = 0; i <= n_pedras+1; i++){
      if(pedras[i].tipo == 'S') cont_pedras_peq++;
      if(pedras[i].tipo == 'B' || (cont_pedras_peq % 2 == 0 && pedras[i].tipo == 'S')){
        //cout << "pulei em " << pedras[i].dis_margem << ", estava em " << dist_percorrida << endl;
        max_pulo = max(max_pulo, pedras[i].dis_margem - dist_percorrida);
        dist_percorrida = pedras[i].dis_margem;
      }
    }

    cont_pedras_peq++;

    for(int i = n_pedras; i >= 0; i--){
      if(pedras[i].tipo == 'S') cont_pedras_peq--;
      if(pedras[i].tipo == 'B' || cont_pedras_peq % 2 == 1 && pedras[i].tipo == 'S'){

        //cout << "pulei em " << pedras[i].dis_margem << ", estava em " << dist_percorrida << endl;
        max_pulo = max(max_pulo, dist_percorrida - pedras[i].dis_margem);
        dist_percorrida = pedras[i].dis_margem;
      }
    }

    cout << "Case " << k+1 << ": " << max_pulo << endl;
     
  }
}
