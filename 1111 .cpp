#include <bits/stdc++.h>

using namespace std;

map <pair<int, int>, vector <pair<int, int>>> g;
map <pair<int, int>, bool> visited;
map <pair<int, int>, int> distance_bfs;

void bfs(pair<int, int> s){
  visited[s] = true;
  distance_bfs[s] = 0;
  queue <pair<int, int>> q;

  q.push(s);

  while(!q.empty()){
    //cout << q.front().first << " " << q.front().second << " vizinhos: " << endl;

    pair <int, int> curr_pros = q.front();
    q.pop();
    for(auto x: g[curr_pros]){
    //cout << x.first << " " << x.second << endl;
      if(visited[x]) continue;
      visited[x] = true;
      distance_bfs[x] = distance_bfs[curr_pros]+1;
      q.push(x);
    }
  }
}

int main(){
  int n; 
  while(cin >> n){
    if(n==0) break;

    for(int j = n-1; j >= 0; j--){
      for(int i = 0; i < n; i++){
        bool no, so, le, oe; cin >> no >> so >> le >> oe;
        vector <pair<int, int>> go_to;

        if(no) go_to.push_back({i, j+1});
        if(so) go_to.push_back({i, j-1});
        if(le) go_to.push_back({i-1, j});
        if(oe) go_to.push_back({i+1, j});
        pair<int, int> curr_pos = {i, j};

        g[curr_pos] = go_to;
      }
    }
    int num_q; cin >> num_q;
    while(num_q--){
      int x0, y0, x1, y1; cin >> x0 >> y0 >> x1 >> y1;
      bfs({x0, y0});

      pair<int, int> to={x1,y1};
      int d = distance_bfs[to];

      if(d == 0 && (x0 != x1 || y0 != y1))
        cout << "Impossible" << '\n';
      else
        cout << d << '\n';

      distance_bfs.clear();
      visited.clear();
    }
    g.clear();
    cout << endl;
  }
}
