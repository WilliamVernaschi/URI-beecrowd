#include <iostream>
#include <vector>
#include <cstring>
#include <set>
using namespace std;
vector <set<int>> g;
bool visited[21];
string spaces(int d){
  string out;
  for(int i = 0; i < d; i++) out += "  ";
  return out;
}
int num_visited(){
  int n_visited=0;
  for(int i = 0; i < 21; i++)
    n_visited += visited[i];
    return n_visited;
}
void dfs(int s, int depth){
  visited[s] = true;
  for(auto neighb : g[s]){
    cout << spaces(depth) << s << "-" << neighb;
    if(visited[neighb]){
      cout << '\n';
      continue;
    }
    cout << " pathR(G," << neighb << ")" << '\n';
    dfs(neighb, depth+1);
  }
}
int main(){
  int t; cin >> t;
  for(int z=1; z<=t; z++){
    int n, e; cin >> n >> e;
    g.resize(n);
    for(int i = 0; i < e; i++){
      int from, to; cin >> from >> to;
      g[from].insert(to);
    }
    cout << "Caso " << z << ":" << '\n';
    int i = 0;
    while(i < n){
      if(!visited[i]){
        int prev_visited = num_visited();
        dfs(i, 1);
        int after = num_visited();
        if(after > prev_visited+1) cout << '\n';
      }
      i++;
    }
    memset(visited, 0, 21*sizeof(bool));
    g.clear();
  }
  return 0;
}
