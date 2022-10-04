#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

int main(){
  ll n; cin >> n;
  ll tot=0;

  for(ll i = 1; i < ((ll)1 << 60); i=(i << 1)){
    tot += ((n & i) != 0);
  }
  cout << (ll)pow(2,tot) << endl;
  return 0;
}

