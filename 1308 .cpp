#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

ll solve(ll x){
  return ((-1 + sqrt(1+8*x))/2.0);
}

int main(){
  ll n; cin >> n;
  while(n--){
    ll x; cin >> x;
    cout << solve(x) << endl;
  }
}
