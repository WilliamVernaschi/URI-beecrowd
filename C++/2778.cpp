#include <iostream>
#include <climits>
using namespace std;
int dp[102][102][21][21][3];
int mat[102][102];
int n, m;
const int INF = INT_MAX/2;
// min reachable = (-100)*(100)^2 = -10e6
const int UNREACHABLE=-10000007;
void reset_dp(int dp[102][102][21][21][3]){
  for(int i = 0; i < 102; i++)
    for(int j = 0; j < 102; j++)
      for(int k = 0; k < 21; k++)
        for(int u = 0; u < 21; u++)
          for(int v = 0; v < 3; v++)
            dp[i][j][k][u][v] = UNREACHABLE;
}
// came_from == 0 -> down
// came_from == 1 -> left
// came_from == 2 -> right
int min_dis(int i, int j, int rem_null, int rem_neg, int came_from){
  if(dp[i][j][rem_null][rem_neg][came_from] != UNREACHABLE) return dp[i][j][rem_null][rem_neg
  if(i < 1 || i > n || j < 1 || j > m || rem_null == 0 || rem_neg == 0) dp[i][j][rem_null][  
  else if(i == n && j == m) dp[i][j][rem_null][rem_neg][came_from] = 0;
    else{
    int down, right, left;
    down = mat[i+1][j] + min_dis(i+1, j, rem_null - (mat[i+1][j] == 0), rem_neg - (mat[i+1]   
    if(came_from == 1) right = INF;
    else right = mat[i][j+1] + min_dis(i, j+1, rem_null - (mat[i][j+1] == 0), rem_neg - (mat   
        if(came_from == 2) left = INF;
    else left = mat[i][j-1] + min_dis(i, j-1, rem_null - (mat[i][j-1] == 0), rem_neg - (mat   
        dp[i][j][rem_null][rem_neg][came_from] = min(min(right, left), down);
  }
  return dp[i][j][rem_null][rem_neg][came_from];
}
int main(){
  int x, y; 
  while(cin >> n >> m >> x >> y){
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= m; j++)
        cin >> mat[i][j];
              x++; y++;
    reset_dp(dp);
    int res = mat[1][1]+min_dis(1, 1, x-(mat[1][1] == 0), y-(mat[1][1] < 0), 0);
    if(res > INF/4){
      cout << "Impossivel" << endl;
    }
    else
      cout << res << endl;
  }
}
