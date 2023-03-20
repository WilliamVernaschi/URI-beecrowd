#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;
bool visitado[27];
vector <vector<int>> grafo;
set <char> resposta;
void dfs(int i){
  resposta.insert((char)(i+'a'));
  visitado[i] = true;
  //cout << "visitei o " << i << endl;
  //cout << (char)(i+'a') << ",";
  for(auto vizinho : grafo[i]){
    //cout << i << " " << vizinho << endl;
    if(visitado[vizinho]) continue;
    dfs(vizinho);
  }
}
int main(){
  int n; cin >> n;
  for(int k=1; k<=n; k++){
    memset(visitado, 0, 27*sizeof(bool));
    grafo = vector<vector<int>> ();
    int v, e; cin >> v >> e;
    grafo.resize(v);
    for(int i = 0; i < e; i++){
      char from, to; cin >> from >> to;
      //cout << from - 'a' << " " << to - 'a' << endl;
      grafo[from - 'a'].push_back(to - 'a');
      grafo[to - 'a'].push_back(from - 'a');
    }
    cout << "Case #" << k << ":" << endl;
    int cont = 0;
    for(int i = 0; i < v; i++){
      if(!visitado[i]){
        dfs(i);
        for(auto el : resposta){
          cout << el << ",";
        }
        cont++;
        resposta = set <char> ();
        cout << endl;
      }
    }
    cout << cont << " connected components" << endl;
    cout << endl;
  }
  return 0;
}
