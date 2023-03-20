#include <iostream>
using namespace std;
int cont=0;
int fibo(int n){
  cont++;
  if(n < 2){
    return n;   
  }
  else{
    return fibo(n-1) + fibo(n-2);
  }
}
int main(){
  int k, n; cin >> k;
  while(cin >> n){
    cont = 0;
    int result = fibo(n);
    cout << "fib(" << n << ") = " << cont-1 << " calls = " << result << endl;
  }
  return 0;
}
