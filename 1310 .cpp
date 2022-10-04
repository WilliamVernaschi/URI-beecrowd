#include <iostream>
#include <cstring>

using namespace std;

int pdc;
int prefix[55];
int dp[55][55];
int solve(int i, int j){
  //cout << i << " " << j << endl;
  if(dp[i][j] != -1){
    return dp[i][j];
  }
  else if(i == j)
    dp[i][j] = 0;
  else{
    int curr = (prefix[j] - prefix[i]) - (j-i)*(pdc);
    //cout << i << " " << j << " " << curr << endl;
    dp[i][j] = max(curr, max(solve(i+1, j), solve(i, j-1)));
  }
  return dp[i][j];
}

int main(){
  int n; 
  while(cin >> n >> pdc){

    for(int i = 0; i < 55; i++){
      prefix[i] = 0;
    }
    for (int i = 1; i <= n; i++){
      int x; cin >> x;
      prefix[i] = prefix[i - 1] + x;
    }
    //for (int i = 0; i <= n; i++){
    //  cout << prefix[i] << endl;
    //}
    memset(dp, -1, 55*55*sizeof(int));
    cout << solve(0, n+1) << endl;
  }
}
