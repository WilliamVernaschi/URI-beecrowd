#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

int dp[102][102][21][21][4];
int mat[102][102];
int n, m;

const int INF = INT_MAX/2;
const int UNREACHABLE=-10000007;


void reset_dp(int dp[102][102][21][21][4]){
  for(int i = 0; i < 102; i++){
    for(int j = 0; j < 102; j++){
      for(int k = 0; k < 21; k++){
        for(int u = 0; u < 21; u++){
          for(int v = 0; v < 4; v++){
            dp[i][j][k][u][v] = UNREACHABLE;
          }
        }
      }
    }
  }
}


// came_from == 0 -> down
// came_from == 1 -> left
// came_from == 2 -> right


// nao ta detectando quando acaba x ou y direito
bool eh_possivel(int i, int j, int x, int y, int came_from){
  //cout << i << " " << j << " " << x << " " << y << endl;
  if(dp[i][j][x][y][came_from] != UNREACHABLE) return dp[i][j][x][y][came_from];
  else if(x == 0 || y == 0 || i < 1 || i > n || j > m || j < 1)
    dp[i][j][x][y][came_from] = false;
  else if(i == n && j == m)
    dp[i][j][x][y][came_from] = true;
  else
    dp[i][j][x][y][came_from] = eh_possivel(i+1, j, x-(mat[i+1][j] == 0, 0), y-(mat[i+1][j] < 0), 0) || (came_from != 1 && eh_possivel(i, j+1, x-(mat[i][j+1] == 0), y-(mat[i][j+1] < 0), 2)) || (came_from != 2 && eh_possivel(i, j-1, x-(mat[i][j-1] == 0), y-(mat[i][j-1] < 0), 1));

  return dp[i][j][x][y][came_from];
}


int min_dis(int i, int j, int rem_null, int rem_neg, int came_from){
  //cout << i << " " << j << " " << rem_null << " " << rem_neg << " " << came_from << endl;
  if(dp[i][j][rem_null][rem_neg][came_from] != UNREACHABLE) return dp[i][j][rem_null][rem_neg][came_from];
  if(i < 1 || i > n || j < 1 || j > m || rem_null == 0 || rem_neg == 0){
    dp[i][j][rem_null][rem_neg][came_from] = INF;
  }
  else if(i == n && j == m){
    dp[i][j][rem_null][rem_neg][came_from] = 0;
  }
  else{
    int down, right, left;
    down = mat[i+1][j] + min_dis(i+1, j, rem_null - (mat[i+1][j] == 0), rem_neg - (mat[i+1][j] < 0), 0);

    if(came_from == 1) right = INF;
    else right = mat[i][j+1] + min_dis(i, j+1, rem_null - (mat[i][j+1] == 0), rem_neg - (mat[i][j+1] < 0), 2);
    
    if(came_from == 2) left = INF;
    else left = mat[i][j-1] + min_dis(i, j-1, rem_null - (mat[i][j-1] == 0), rem_neg - (mat[i][j-1] < 0), 1);
    
    dp[i][j][rem_null][rem_neg][came_from] = min(min(right, left), down);
  }
  return dp[i][j][rem_null][rem_neg][came_from];
}

int main(){
  int x, y; 
  while(cin >> n >> m >> x >> y){
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= m; j++){
        cin >> mat[i][j];
      }
    }
    x++; y++;

    //reset_dp(dp);
    //cout << eh_possivel(1, 1, x-(mat[1][1] == 0), y-(mat[1][1] < 0), 0) << endl;
    reset_dp(dp);

    int res = mat[1][1]+min_dis(1, 1, x-(mat[1][1] == 0), y-(mat[1][1] < 0), 0);
    /*
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= m; j++){
        for(int k = 0; k < x; k++){
          for(int v = 0; v < y; v++){
            for(int u = 0; u < 3; u++){
                cout << i << " " << j << " " << k << " " << v << " " << u << " " << dp[i][j][k][v][u] << endl;
              
            }
          }
        }
      }
    }
    */
    if(res > INF/4){
      cout << "Impossivel" << endl;
    }
    else
      cout << res << endl;

  }
}
