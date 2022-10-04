#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll intpow(int x, int n){
  if(n == 0){
    return 1;
  }
  else if(n % 2 == 1){
    return x*intpow(x,n-1);
  }
  else{
    return intpow(x,n/2)*intpow(x,n/2);
  }
}

ll eulerphi(vector <ll> &prime_facs) {
  ll n = 1;
  int curr_p = prime_facs[0];
  int curr_count = 1;
  for(int i = 0; i < prime_facs.size()-1; i++){
    if(prime_facs[i] == prime_facs[i+1]){
      curr_count++;
    }
    else{
      n *= intpow(curr_p, curr_count-1) * (curr_p - 1);
      curr_count = 1;
      curr_p = prime_facs[i+1];
    }
  }
  n *= intpow(curr_p, curr_count-1) * (curr_p - 1);
  return n;
}

int main(){
  ll n;
  while(cin >> n){
    vector <ll> facs;
    for(ll x = 2; x*x <= n; x++){
      while(n%x == 0){
        facs.push_back(x);
        n /= x;
      }
    }
    if(n > 1) facs.push_back(n);

    
    int phi = eulerphi(facs);
    cout << phi/2 + phi%2 << endl;
  }

}
