#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

vector <vector <int>> graph;

bool visited[2005];
int num_visited=1;

void dfs(int start){
  visited[start] = true; 
  for(int v : graph[start]){
    if(visited[v]) continue;
    visited[v] = true;
    num_visited++;
    dfs(v);
  }
}

int main(){
  int v, e; 
  while(cin >> v >> e){
    if(v+e == 0) break;


    graph = vector <vector<int>> ();
    graph.resize(v+1);
    
    for(int i = 1; i <= e; i++){
      int from, to, bi; cin >> from >> to >> bi; bi--;
      if(bi){
        graph[from].push_back(to);
        graph[to].push_back(from);
      }
      else
        graph[from].push_back(to);
    }

    bool ok=1;
    for(int i =1; i <= v && ok==1; i++){
      memset(visited, 0, sizeof(bool)*2005);
      num_visited=1;
      dfs(i);
      ok = ok && num_visited == v;
    }

    cout << ok << endl;
  }
  return 0;
}
