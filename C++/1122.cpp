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
int dp[42][40000][2];
const int OFFSET=2e4;
int arr[45];
int n, t;
bool solve(int idx, int sum, bool issum){
  if(dp[idx][sum][issum] != -1) return dp[idx][sum][issum];
  if(sum-OFFSET == t && idx == n) dp[idx][sum][issum] = true;
  else if(idx == n) dp[idx][sum][issum] = false;
  else{
    bool dosum = solve(idx+1, sum + arr[idx], 1);
    bool dosub = solve(idx+1, sum - arr[idx], 0);
    dp[idx][sum][issum] = dosum || dosub;
  }
  return dp[idx][sum][issum];
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  while(cin >> n >> t){
    memset(dp, -1, sizeof(dp));
    if(n+t == 0) return 0;
    int ss=0;
    for(int i = 0; i < n; i++){
      cin >> arr[i];
      ss += arr[i];
    }
    bool isok = solve(0, OFFSET, 0);
    if(!isok){
      cout << '*' << endl;
      continue;
    }
    vector<pair<int, int>> ans(n+1, {0, 0});
    for(int i = 1; i <= n; i++){
      for(int j = OFFSET-ss-1; j <= OFFSET+ss+1; j++){
        for(int k = 0; k <= 1; k++){
          if(dp[i][j][k] == 1){
            if(k == 0) ans[i].F = 1;
            else if(k == 1) ans[i].S = 1;
          }
        }
      }
    }
    bool idx=false;
    for(auto x : ans){
      if(!idx){
        idx=true;
        continue;
      }
      if(x.F == x.S) cout << '?';
      else if(x.F) cout << '-';
      else cout << '+';
    }
    cout << endl;
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
