#include <iostream>
using namespace std;
typedef long long ll;
int B;
void mult(int a[3][3], int b[3][3], int res[3][3]){
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      for(int k = 0; k < 3; k++){
        res[i][j] += a[i][k] * b[k][j];
        res[i][j] = res[i][j] % B;
      }
    }
  }
}
void ident(int res[3][3]){
  res[0][0] = res[1][1] = res[2][2] = 1;
}
void expbin(int a[3][3], ll n, int res[3][3]){
  int aux[3][3] = {0};
  if(n == 0){
    ident(res);
    return;
  }
  else{
    expbin(a, n/2, aux);
  }
  if(n % 2 == 1){
    int aux2[3][3] = {0};
    mult(aux, aux, aux2);
    mult(aux2, a, res);
  }
  else{
    mult(aux, aux, res);
  }
}
int main(){
  long long n; 
  int t = 1;
  while(cin >> n >> B){
    if(n+B == 0) return 0;
    int initv[3] = {1, 1, 1};
    int mat_transf[3][3] = {{1, 1, 1}, {1, 0, 0}, {0, 0, 1}};
    int mat_end[3][3] = {0};
    expbin(mat_transf, n-1, mat_end);
    cout << "Case " << t << ": " << n << " " << B << " ";
    cout << ((mat_end[0][0]*initv[0] + mat_end[0][1]*initv[1] + mat_end[0][2]*initv[2]) % B  
    t++;
  }
}
