#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int INF=10000000;
struct cily{
  int h, r, col;
};
// col == 0 :red
// col == 1: orange
// col == 2: blue
// col == 3: green
int col_code(string s){
  if(s == "VERMELHO") return 0;
  if(s == "LARANJA")  return 1;
  if(s == "AZUL")     return 2;
  if(s == "VERDE")    return 3;
  cerr << "ERRO" << endl;
  return -1;
}
string col(int n){
  if(n == 0) return "VERMELHO";
  if(n == 1) return "LARANJA";
  if(n == 2) return "AZUL";
  if(n == 3) return "VERDE";
  else return "ANY";
}
// can i place c1 on top of c2
bool can_place(int color1, int color2){
  bool res = 
  (color1 == 0 && color2 != 1) ||
  (color1 == 1 && color2 != 2) ||
  (color1 == 2 && color2 != 3) ||
  (color1 == 3 && color2 != 0) ||
  (color2 == 4);
  if(res){
    //cout << "vou colocar " << col(color1) << " em cima de " << col(color2) << endl;
    return true;
  }
  else{
    //cout << "NÃO vou colocar " << col(color1) << " em cima de " << col(color2) << endl;
  return false;
  }
}
bool comp(cily c1, cily c2){
  return c1.r > c2.r;
}
cily cilindros[1001];
int dp[1002][1002];
int n;
int solve(int idx, int prev_idx){
  //cout << idx << " " << col(color) << endl;
  if(dp[idx][prev_idx] != -1) return dp[idx][prev_idx];
  else if(idx == n+1){
    dp[idx][prev_idx] = 0;
  }
  else{
    int placed;
    int didnt = solve(idx+1, prev_idx);
    if(can_place(cilindros[idx].col, cilindros[prev_idx].col) && cilindros[idx].r < cilindros
      placed = cilindros[idx].h + solve(idx+1, idx);
    }
    else{
      dp[idx][prev_idx] = didnt;
      return didnt;
    }
    dp[idx][prev_idx] = max(placed, didnt);
  }
  return dp[idx][prev_idx];
}
int main(){
  while(cin >> n){
    if(!n) break;
    for(int i = 1; i <= n; i++){
      cily c; cin >> c.h >> c.r;
      string col; cin >> col;
      c.col = col_code(col);
      cilindros[i] = c;
    }
    sort(cilindros+1, cilindros+n+1, comp);
    cily c; c.r = INF;
    c.h = 0;
    c.col = 4;
    cilindros[0] = c;
    /*
    for(int i = 0; i < n; i++){
      cout << cilindros[i].h << " " << cilindros[i].r << " " << cilindros[i].col << endl;
    }
    */
    memset(dp, -1, 1002*1002*sizeof(int));
    cout << solve(0, 0) << " centimetro(s)" << endl;
  }
   }
