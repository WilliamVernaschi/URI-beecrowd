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
const int MAX_SIZE=6e3;
string s1, s2;
int dp[MAX_SIZE][MAX_SIZE];
int lcs(int i1, int i2){
  if(dp[i1][i2] != -1) return dp[i1][i2];
  if(i1 == 0 || i2 == 0) dp[i1][i2] = 0;
  else if(s1[i1] == s2[i2]) dp[i1][i2] = 1 + lcs(i1-1, i2-1);
  else dp[i1][i2] = max(lcs(i1-1, i2), lcs(i1, i2-1));
  return dp[i1][i2];
}
int main(){
  cin >> s1 >> s2;
  s1 = " " + s1;
  s2 = " " + s2;
  memset(dp, -1, MAX_SIZE*MAX_SIZE*sizeof(int));
  cout << lcs(s1.size()-1, s2.size()-1) << endl;
}
