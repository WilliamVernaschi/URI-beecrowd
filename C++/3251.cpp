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
typedef pair<int, int> pii;
const int INF=1e9+7;
string p, t;
int dp[101][101];
bool solve(int i, int j){
  if(dp[i][j] != -1) return dp[i][j];
  if(i == p.size() && j == t.size()) dp[i][j] = true;
  else if(i == p.size() || j == t.size()) dp[i][j] = false;
  else if(p[i] == '*'){
    dp[i][j] = solve(i+1, j) || solve(i, j+1) || solve(i+1, j+1);
  }
  else if(p[i] == t[j]){
    dp[i][j] = solve(i+1, j+1);
  }
  else{
    dp[i][j] = false;
  }
  return dp[i][j];
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> p;
  int n; cin >> n;
  for(int i = 0; i < n; i++){
    cin >> t;
    memset(dp, -1, sizeof(dp));
    if(solve(0, 0)){
      cout << t << endl;
    }
  }
}
