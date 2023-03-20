#include <iostream>
#include <cstring>
using namespace std;
const int MAX=100005;
int dp[MAX];
int best_sum(int idx, int arr[], int n){
  if(dp[idx]) return dp[idx];
  if(idx >= n){
    dp[idx] = 0;
  }
  else{
    dp[idx] = max(arr[idx] + best_sum(idx+2, arr, n), best_sum(idx+1, arr, n));
  }
  return dp[idx];
}
int main(){
  int m, n; 
  int line[MAX];
  int columns[MAX];
  while(cin >> m >> n){
    if(m+n == 0) break;
    for(int i = 0; i < m; i++){
      for(int j = 0; j < n; j++){
        cin >> line[j];
      }
      columns[i] = best_sum(0, line, n);
      memset(dp, 0, MAX*sizeof(int));
    }
    cout << best_sum(0, columns, m) << endl;
    memset(dp, 0, MAX*sizeof(int));
  }
}
