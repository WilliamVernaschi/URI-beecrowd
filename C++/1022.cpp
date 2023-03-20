#include <iostream>
#include <cmath>
using namespace std;
int mdc(int a, int b){
  if(b == 0) return a;
  return mdc(b, a%b);
}
int main(){
  int n; cin >> n;
  while(n--){
    int n1, d1, n2, d2;
    char _, op;
    int new_n, new_d;
    cin >> n1 >> _ >> d1 >> op >> n2 >> _ >> d2;
    switch(op){
      case '+':
        new_n = (n1*d2 + n2*d1);
        new_d = (d1*d2);
        break;
      case '-':
        new_n = n1*d2 - n2*d1;
        new_d = d1*d2;
        break;
      case '*':
        new_n = n1*n2;
        new_d = d1*d2;
        break;
      case '/':
        new_n = n1*d2;
        new_d = n2*d1;
        break;
    }
    int m = mdc(abs(new_n), abs(new_d));
    cout << new_n << "/" << new_d << " = " << new_n/m << "/" << new_d/m << endl;
      }
  return 0;
}
