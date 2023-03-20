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
string s1, s2;
int dp[55][55][55];
int lcs(int i1, int i2, int cur){
  if(dp[i1][i2][cur] != -1) return dp[i1][i2][cur];
  if(i1 == s1.size() || i2 == s2.size()) dp[i1][i2][cur] = cur;
  else{
    int cnt = cur;
    if(s1[i1] == s2[i2]){
      cnt = lcs(i1+1, i2+1,cur+1);
    }
    cnt = max(cnt,
                 max(lcs(i1, i2+1, 0),
                    lcs(i1+1, i2, 0)));
    dp[i1][i2][cur] = cnt;
  }
  return dp[i1][i2][cur];
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  while(getline(cin, s1) && getline(cin, s2)){
    //cout << s1 << " " << s2 << endl;
    memset(dp, -1, 55*55*55*sizeof(int));
    cout << lcs(0, 0, 0) << endl;
  }
}
