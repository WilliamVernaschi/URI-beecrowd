#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define endl "\n"
const int INF = 10000006;
int main(){
  int t; cin >> t;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int dp[1000005];
  int coins[30];
  while(t--){
    int g, n; cin >> n >> g;
    memset(dp, -1, 1000005*sizeof(int));
    for(int i = 0; i < n; i++){
      cin >> coins[i];
    }
    dp[0] = 0;
    for (int x = 1; x <= g; x++) {
      dp[x] = INF;
      for (int i = 0; i < n; i++) {
        if (x-coins[i] > -1) {
          dp[x] = min(dp[x], dp[x-coins[i]]+1);
      }
    }
}
    cout << dp[g] << endl;
  }
  return 0;
}
