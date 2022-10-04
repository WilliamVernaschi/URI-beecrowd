#include <iostream>
#include <cstring>

using namespace std;


const int INF = 0x3f3f3f3f;

struct deliv{
  int time;
  int num_pizzas;
};

deliv pizzas[22];

int dp[22][32];

int solverec(int idx, int p){
  //cout << idx << " " << p << endl;
  if(p < 0)                     return -INF;
  else if(dp[idx][p] != -1)     return dp[idx][p];
  else if(p == 0 || idx == 0)   dp[idx][p] = 0;
  else                          dp[idx][p] = max(pizzas[idx].time + solverec(idx-1, p-pizzas[idx].num_pizzas), solverec(idx-1, p));
  
  return dp[idx][p];
}

int solveit(int idx, int p){
  for(int i = 1; i <= idx; i++){
    for(int j = 1; j <= p; j++){
      if(j-pizzas[i].num_pizzas >= 0)
        dp[i][j] = max(pizzas[i].time + dp[i-1][j-pizzas[i].num_pizzas], dp[i-1][j]);
      else
        dp[i][j] = dp[i-1][j];
      
    }
  }
  return dp[idx][p];
}

int main(){
  
  int n;
  while(cin >> n){
    if(!n) break;
    int max_p; cin >> max_p;
  
    for(int i = 1; i <= n; i++){
      cin >> pizzas[i].time;
      cin >> pizzas[i].num_pizzas;
    }

    memset(dp, -1, 22*32*sizeof(4));
    
    for(int i = 0; i < 32; i++)
      dp[0][i] = 0;

    for(int i = 0; i < 22; i++)
      dp[i][0] = 0;
    

    cout << solveit(n, max_p) << " min." << endl;
  }
  
  return 0;
}
