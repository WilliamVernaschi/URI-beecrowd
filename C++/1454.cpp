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
void djikstra(int s){
  int n = g.size();
  d.assign(n, INF);
  vector<bool> u(n, false);
  d[s] = -INF;
  for(int i = 0; i < n; i++){
    int v = -1;
    for(int j = 0; j < n; j++){
      if(!u[j] && (v == -1 || d[j] < d[v])) v = j;
    }
    if(d[v] == INF) break;
    u[v] = true;
    for(auto u : g[v]){
      int to = u.F;
      int w = u.S;
      d[to] = min(d[to], max(d[v], w));
    }
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  int inst=1;
      while(cin >> n >> m){
    if(n+m == 0) break;
    cout << "Instancia " << inst << endl;
    inst++;
    g.resize(n);
    for(int i = 0; i < m; i++){
      int a, b, w; cin >> a >> b >> w;
      a--; b--;
      g[a].PB({b, w});
      g[b].PB({a, w});
    }
    int q; cin >> q;
    while(q--){
      int from, to; cin >> from >> to;
      from--; to--;
      if(from == to){
        cout << 0 << endl;
        continue;
      }
      djikstra(from);
      cout << d[to] << endl;
      //d.clear();
    }
    g.clear();
    cout << endl;
  }
}
