#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
typedef long long ll;
long double fixSign(long double d)
{
    std::ostringstream strs;
    strs << std::fixed << std::setprecision(2) << d;
    std::string str = strs.str();
    if (str == "-0.00") return 0.0;
    return d;
}
double roundit(long double x){
  double ok = round(x * 100.0) / 100.0;
  if(ok == 0){
    return 0;
  }
  return ok;
}
const long double PI = 3.14159265358979323846264;
void mult(long double a[3][3], long double b[3][3], long double res[3][3]){
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      for(int k = 0; k < 3; k++){
        res[i][j] += a[i][k] * b[k][j];
      }
    }
  }
}
void ident(long double res[3][3]){
  res[0][0] = res[1][1] = res[2][2] = 1;
}
void expbin(long double a[3][3], ll n, long double res[3][3]){
  long double aux[3][3] = {0};
  if(n == 0){
    ident(res);
    return;
  }
  else{
    expbin(a, n/2, aux);
  }
  if(n % 2 == 1){
    long double aux2[3][3] = {0};
    mult(aux, aux, aux2);
    mult(aux2, a, res);
  }
  else{
    mult(aux, aux, res);
  }
}
int main(){
  int t; cin >> t;
  while(t--){
    long long n;
    long double alph, l; cin >> alph >> l >> n;
    alph = (PI/180)*alph;
    long double initv[3] = {0, 0, 1};
    long double mat_transf[3][3] = {{cos(alph), -sin(alph), l}, {sin(alph), cos(alph), 0}, {0  
    long double mat_end[3][3] = {0};
    expbin(mat_transf, n, mat_end);
    long double r1 = (mat_end[0][0]*initv[0] + mat_end[0][1]*initv[1] + mat_end[0][2]*initv[2
    long double r2 = (mat_end[1][0]*initv[0] + mat_end[1][1]*initv[1] + mat_end[1][2]*initv[2
          /*
    if(abs(r1 - 0) < 0.01){
      cout << "???????????????";
      r1 = 0;
    }
    if(abs(r2 - 0) < 0.01){
      cout << "???????????????";
      r2 = 0;
    }
    */
        cout << fixed << setprecision(2) << fixSign(r1) << " " << fixSign(r2) << endl;
  }
}
