#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
struct ball{
  int power;
  int weight;
};
ball balls[51];
int dp[101][51];
//int calls = 0;
// dados o peso máximo que o canhão aguenta canhão e o índice da última bola que podemos colocar (se k = 3, vamos tentar colocar as bolas 1, 2, e 3), retorna o poder máximo de destruição.
int solve(int max_weight, int k){
  if(dp[max_weight][k] != -1) return dp[max_weight][k];
  int result;
  if(max_weight == 0 || k == 0) // caso base (se o peso máximo é 0, ou não tem mais bolas pra colocar, o poder máximo é 0)
    dp[max_weight][k] = 0;
  else if(balls[k].weight > max_weight){ // nao dá pra colocar a bola
    dp[max_weight][k] = solve(max_weight, k-1); 
  }
  else{
    int colocou = balls[k].power + solve(max_weight - balls[k].weight, k-1); // poder maximo se colocou a bola k-esima bola
    int nao_colocou = solve(max_weight, k-1); // poder maximo se nao colocou
    dp[max_weight][k] = max(colocou, nao_colocou);
  }
  return dp[max_weight][k];
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n_cases; cin >> n_cases;
  while(n_cases--){
    int n_balls; cin >> n_balls;
    balls[0] = {0, 0};
    for(int i = 1; i <= n_balls; i++){
      cin >> balls[i].power;
      cin >> balls[i].weight;
    }
    int max_weight, max_destr; cin >> max_weight >> max_destr;
        memset(dp, -1, 101*51*sizeof(int));
    int destr = solve(max_weight, n_balls);
    if(destr >= max_destr)
      cout << "Missao completada com sucesso" << '\n';
    else
      cout << "Falha na missao" << '\n';
    //cout << calls << endl;
    //calls = 0;
  }
  return 0;
}
