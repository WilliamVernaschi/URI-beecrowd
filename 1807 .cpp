#include <iostream>

using namespace std;

typedef long long ll;
ll MOD=2147483647;

ll mypow(ll b, int n){
  if(n == 0){
    return 1;
  }
  if(n % 2){
    return (b*(mypow(b, n-1)%MOD))%MOD;
  }
  else{
    return ((mypow(b, n/2)%MOD)*(mypow(b, n/2)%MOD))%MOD;
  }
}

int main(){
  int n; cin >> n;
  cout << (mypow(3, n) % MOD) << endl;
}
