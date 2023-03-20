#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
typedef unsigned int uint;
typedef long long ll;
ll count(ll x){
  ll ans=0;
  for(ll i = 1; i < (1ull << 63); i = (i << 1)){
    if(x/i % 2 == 0){
      ans += i*((x/i)/2);
    }
    else{ // x/i % 2 == 0
      ans += x%i+1 + i*((x/i)/2);
    }
  }
  return ans;
}
int main(int argc, char* argv[]){
    ll a, b;
  while(cin >> a >> b){
    cout << count(b) - count(a-1) << endl;
  }
}
