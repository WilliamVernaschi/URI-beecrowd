#include <iostream>
using namespace std;
typedef long long ll;
int B=1000;
void mult(int a[2][2], int b[2][2], int res[2][2]){
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 2; j++){
      for(int k = 0; k < 2; k++){
        res[i][j] += a[i][k] * b[k][j];
        res[i][j] = res[i][j] % B;
      }
    }
  }
}
void ident(int res[2][2]){
  res[0][0] = res[1][1] = 1;
}
void expbin(int a[2][2], ll n, int res[2][2]){
  int aux[2][2] = {0};
  if(n == 0){
    ident(res);
    return;
  }
  else{
    expbin(a, n/2, aux);
  }
  if(n % 2 == 1){
    int aux2[2][2] = {0};
    mult(aux, aux, aux2);
    mult(aux2, a, res);
  }
  else{
    mult(aux, aux, res);
  }
}
int mod1500(string num){
  int res = 0;
  for(int i = 0; i < num.size(); i++){
    res = (res * 10 + (int)num[i] - '0') % 1500;
  }
  return res;
}
int main(){
  int t; cin >> t;
  string ns; 
  while(t--){
    cin >> ns;
    ll n = mod1500(ns);
    if(n == 0){
      printf("000\n");
      continue;
    }
    int mat_transf[2][2] = {{1, 1}, {1, 0}};
    int mat_end[2][2] = {0};
    expbin(mat_transf, n-1, mat_end);
    printf("%03d\n", mat_end[0][0]);
  }
}
