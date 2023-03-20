#ifdef ONLINE_JUDGE
  #define debug(x...)
#else
  #include "/mnt/d/dev/cp/debug.h"
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
int invnum(int n){
  int ans=0;
  int nd=0;
  int x=n;
  while(x){
    x/=10;
    nd++;
  }
  for(int i = nd; i > 0; i--){
    ans += (n%10)*pow(10,i-1);
    n /= 10;
  }
  return ans;
}
int main(){
  FFIO;
  int t; cin >> t;
  while(t--){
    unordered_map<int, int> state;
    int a, b; cin >> a >> b;
    state[a] = 0;
        auto bfs = [&](int from, int to){
      queue<int> q;
      q.push(from);
      while(!q.empty()){
        int v = q.front();
        q.pop();
        int inv = invnum(v);
        int add = v+1;
        if(!state.count(inv)){
          state[inv] = state[v]+1;
          q.push(inv);
          if(inv == to) return;
        }
        if(!state.count(add)){
          state[add] = state[v]+1;
          q.push(add);
          if(add == to) return;
        }
      }
    };
    bfs(a, b);
    cout << state[b] << '\n';
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
