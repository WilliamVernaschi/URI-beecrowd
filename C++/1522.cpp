#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define PER(i,a,b) for(int i = a; i >= b; i--)
#define PMOD(n, m) ((((n) % (m)) + (m)) % (m))
#define debug(x) cerr << #x << " = " << x << endl;
#define debug2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
const int INF=1e9+7;
int stck[105][3];
int dp[105][105][105];
int solve(int i, int j, int k){
  //cout << i << " " << j << " " << k << endl;
  if(i < 0 || j < 0 || k < 0) return false;
  else if(i == 0 && j == 0 && k == 0) dp[i][j][k] = true;
  else if(dp[i][j][k] == -1)
    dp[i][j][k] = ((stck[i][0] % 3 == 0) && solve(i-1, j, k)) ||
                  ((stck[j][1] % 3 == 0) && solve(i, j-1, k)) ||
                  ((stck[k][2] % 3 == 0) && solve(i, j, k-1)) ||
                  (((stck[i][0] + stck[j][1]) % 3 == 0) && solve(i-1, j-1, k)) ||
                  (((stck[i][0] + stck[k][2]) % 3 == 0) && solve(i-1, j, k-1)) ||
                  (((stck[j][1] + stck[k][2]) % 3 == 0) && solve(i, j-1, k-1)) ||
                  (((stck[i][0] + stck[j][1] + stck[k][2]) % 3 == 0) && solve(i-1, j-1, k-1))
  return dp[i][j][k];
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  while(cin >> n){
    if(!n) break;
    PER(i, n, 1){
      cin >> stck[i][0] >> stck[i][1] >> stck[i][2];
    }
    memset(dp, -1, 105*105*105*sizeof(int));
    cout << solve(n, n, n) << endl;
  }
}
