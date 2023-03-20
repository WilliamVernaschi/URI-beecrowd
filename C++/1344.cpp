#ifdef ONLINE_JUDGE
  #define debug(x...)
#else
  #include "/home/william/cp/debug.h"
#endif
#include <bits/stdc++.h>
using namespace std;
#define PMOD(n,m) ((((n) % (m)) + m) % m)
#define F first
#define S second
#define PB push_back
#define FFIO ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;
typedef pair<int, int> pii;
const int INF=1e9+7;
const ll INFLL=1e18+7;
int main(){
  FFIO;
  int n, p, k;
  while(cin >> n >> p >> k){
    if(n == 0) return 0;
    vector<int> score(n, 0);
    vector<vector<int>> g(n);
    vector<bool> forbidden(n, 0);
    set<pair<int, int>> pq;
    for(int i = 0; i < p; i++){
      int a, b; cin >> a >> b;
      a--, b--;
      score[a]++;
      score[b]++;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    for(int i = 0; i < n; i++){
      pq.insert({score[i], i});
    }
    for(int i = 0; i < n; i++){
      if(pq.size() == 0 || pq.begin()->first >= k){
        break;
      }
      int v = pq.begin()->second;
      forbidden[v] = true;
      pq.erase(pq.begin());
      for(int u : g[v]){
        if(pq.find({score[u], u}) == pq.end()) continue;
        pq.erase({score[u], u});
        score[u]--;
        pq.insert({score[u], u});
      }
    }
    function<int(int)> dfs = [&](int v){
      forbidden[v] = true;
      int s = 1;
      for(int u : g[v]){
        if(!forbidden[u]){
          s += dfs(u);
        }
      }
      return s;
    };
    int ans = 0;
    for(int i = 0; i < n; i++){
      if(!forbidden[i]){
        ans = max(dfs(i), ans);
      }
    }
    cout << ans << '\n';
    for(int i = 0; i < n; i++) forbidden[i] = 0;
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
