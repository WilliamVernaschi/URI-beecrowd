#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define PMOD(n, m) ((((n) % (m)) + (m)) % (m))
#define debug(x) cerr << #x << " = " << x << endl;
#define debug2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl;
#define debug3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;
#define debug4(x, y, z, w) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #w << " = " << w << endl;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
const int INF=1e9+7;
vector<vector<pair<int, int>>> g;
vector<int> d;
int c;
void dijkstra(int s){
  int n = g.size();
  vector <int> u(n, false);
  d.assign(n, INF);
  d[s] = 0;
  for(int i = 0; i < n; i++){
    int v=-1;
    for(int j = 0; j < n; j++){
      if(!u[j] && (v == -1 || d[j] < d[v])){
        v = j;
      }
    }
    if(d[v] == INF) break;
    u[v] = true;
    for(auto u : g[v]){
      int to = u.F;
      int len = u.S;
      if(v < c){
        if(to != v+1) continue;
        d[to] = min(d[to], d[v]+len);
      }
      else{
        d[to] = min(d[to], d[v]+len);
      }
    }
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, e, k;
  while(cin >> n >> e >> c >> k){
    if(n+e+c+k == 0) break;
    g.resize(n);
    for(int i = 0; i < e; i++){
      int a, b, w; cin >> a >> b >> w;
      g[a].PB({b,w});
      g[b].PB({a,w});
    }
    dijkstra(k);
    cout << d[c-1] << endl;
    g.clear();
    d.clear();
  }
}
