#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
vector <vector<int>> graph;
int num_paths;
int visited[50];
void dfs(int s){
  visited[s] = true;
  for(int neighbour : graph[s]){
    if(visited[neighbour]) continue;
    //cout << "from " << s << " to " << neighbour << endl;
    num_paths++;
    dfs(neighbour);
    num_paths++;
    //cout << "from " << neighbour << " to " << s << endl;
  }
}
int main(){
  int t; cin >> t;
  while(t--){
    int start; cin >> start;
    int n, e; cin >> n >> e;
    set <pair<int, int>> qqq;
    for(int i = 0; i < e; i++){
      int from, to; cin >> from >> to;
      qqq.insert({from, to});
      qqq.insert({to, from});
    }
    cout << qqq.size() << endl;
  }
}
