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
vector<vector<int>> g;
vector<vector<int>> rev_g;
vector<vector<int>> scc;
vector<vector<int>> scc_els;
vector<int> p;
int components[5005];
bool visited[5005];
void dfs1(int s){
  if(visited[s]) return;
  visited[s] = true;
  for(auto u : g[s]){
    if(!visited[u])
      dfs1(u);
  }
  p.PB(s);
}
bool newc=false;
int scc_cnt=0;
void dfs2(int s){
  if(visited[s]) return;
  visited[s] = true;
  newc = true;
  for(auto u : rev_g[s]){
    if(!visited[u])
      dfs2(u);
  }
  components[s] = scc_cnt;
  scc_els[scc_cnt].PB(s);
}
void dfs3(int s){
  if(visited[s]) return;
  visited[s] = true;
  for(auto u : g[s]){
    dfs3(u);
    if(components[s] != components[u]){
      scc[components[s]].PB(components[u]);
      //cout << components[s] << " points to "  << components[u] << endl;
    }
  }
}
void makescc(int n){
  for(int i = 1; i <= n; i++){
    dfs1(i);
  }
  reverse(p.begin(), p.end());
  memset(visited, 0, (n+1)*sizeof(bool));
  for(int i = 0; i < n; i++){
    dfs2(p[i]);
    if(newc){
      scc_cnt++;
      newc = false;
    }
  }
  memset(visited, 0, (n+1)*sizeof(bool));
  for(int i = 1; i <= n; i++) dfs3(i);
}
vector<int> ans;
void solve(int n){
    //debug(scc_cnt);
  for(int i = 0; i < scc_cnt; i++){
    if(scc[i].size() == 0){
      for(auto u : scc_els[i]) ans.PB(u);
    }
  }
  }
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, e; 
  while(cin >> n){
    if(n == 0) return 0;
    cin >> e;
    g.clear();
    g.resize(n+4);
    rev_g.clear();
    rev_g.resize(n+4);
    p.clear();
    ans.clear();
    scc.clear();
    scc_els.clear();
    scc_els.resize(n+4);
    scc.resize(n+4);
    scc_cnt = 0;
    for(int i = 0; i < e; i++){
      int a, b; cin >> a >> b;
      g[a].PB(b);
      rev_g[b].PB(a);
    }
    makescc(n);
    /*
    for(auto cmp : scc){
      for(auto x : cmp) cout << x << " ";
      cout << endl;
    }
    */
    solve(n);
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++){
      cout << ans[i] << (i != ans.size()-1 ? " " : "");
    }
    cout << '\n';
    memset(visited, 0, sizeof(bool)*(n+2));
    memset(components, 0, sizeof(int)*(n+2));
  }
}
// Stuck? Answer these:
//
// Did I understand the problem correctly?
// Did I read the restrictions carefully? i.e: there is something like n*m < 2e5, when n <= 2e5 and m <= 2e5
// Should I be using long long instead of int somewhere?
// Should I be using double instead of int somewhere?
// Do in need to reset any values after a procedure?
// Is there a tricky pattern to be found? Try bruteforcing a solution to find it.
// No good ideas after around 2h? Try another problem / look up the solution
