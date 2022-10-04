#include <iostream>

using namespace std;

int main(){
  int v, n; cin >> v >> n;
  int coins[n+1];

  for(int i = 0; i < n; i++){
    cin >> coins[i];
  }
  bool dp[100001] = {0};

  dp[0] = true;
  for(int j = 0; j < n; j++){
    for(int i = v; i >=0; i--){
      if(dp[i] && i+coins[j] <= v)
        dp[i+coins[j]] = true;
    }
  }
  cout << (dp[v] ? 'S' : 'N') << endl;
}
