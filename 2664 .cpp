#include <iostream>

using namespace std;


long long dp[51][100005];

long long calc(int min, int max, int minutos, int nivel){
  if(dp[minutos][nivel]) return dp[minutos][nivel];
  //cout << "ai" << '\n';
  else{
    if(nivel >= max){
      dp[minutos][nivel] = calc(min, max, minutos-1, nivel-1);
    }
    else if(nivel <= min){
      dp[minutos][nivel] = calc(min ,max, minutos-1, nivel+1);
    }
    else{
      dp[minutos][nivel] = calc(min ,max, minutos-1, nivel+1) + calc(min ,max, minutos-1, nivel-1);
    }
  }
  return dp[minutos][nivel];
}



int main(){
  int t, m, n; cin >> t >> m >> n;

  for(int i = 0; i < 100005; i++){
    dp[1][i] = 1;
  }

  long long tot = 0;
  for(int i = m; i<= n; i++){
    //cout << i << endl;
    tot += calc(m, n, t, i);
    tot %= 1000000007;
  }
  cout << tot << endl;
  return 0;
}
