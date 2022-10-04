#include <iostream>
#include <cmath>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main(){
  ll x; cin >> x;

  ll num_fatores=0;
  ll i=2;

  while(i*i <= x){
    while(x % i == 0){
      x/=i;
      if(x % i != 0)
        num_fatores++;
      
    }
    if(i == x) num_fatores++;
    i++;
  }
  if(x != 1) num_fatores++;

  ll result = pow(2, num_fatores) - num_fatores-1;

  cout << result << endl;

  
  return 0;
}
