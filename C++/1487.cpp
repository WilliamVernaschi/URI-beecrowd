/*
#ifdef ONLINE_JUDGE
  #define debug(x...)
#else
  #include "/mnt/d/dev/cp/debug.h"
#endif
*/
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
  int n, t, tt=0;
  while(cin >> n >> t){
    if(n == 0){
      break;
    }
    tt++;
    int times[n+1];
    int points[n+1];
    for(int i = 0; i < n; i++){
      cin >> times[i] >> points[i];
    }
    int dp[n+1][t+1];
    for(int i = 0; i <= n; i++){
      dp[i][0] = 0;
    }
    for(int i = 0; i <= t; i++){
      dp[n][i] = 0;
    }
    //solve(i, t) = max(points[i] + solve(i, t-times[i]), solve(i+1, t))
    for(int i = n-1; i >= 0; i--){
      for(int j = 1; j <= t; j++){
        if(j-times[i] >= 0){
          dp[i][j] = max(points[i] + dp[i][j-times[i]], dp[i+1][j]);
        }
        else{
          dp[i][j] = dp[i+1][j];
        }
      }
    }
    cout << "Instancia " << tt << '\n';
    cout << dp[0][t] << "\n\n";
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
