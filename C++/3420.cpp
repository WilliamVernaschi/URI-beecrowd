#include <iostream>
#include <math.h>
using namespace std;
#define ll long long
ll cartas(ll altura)
{
    return (3 * altura + 1) * altura / 2;
}
ll solve(ll x){
  ll res = ((long double)sqrt(6)/(long double)3.0)*sqrt((long double)x);
  //cout << cartas(res) << endl;
  //cout << cartas(res+1) << endl;
  if(cartas(res) > x) return res-1;
  return res;
}
int main()
{
  int n; cin >> n;
  while(n--){
    ll x; cin >> x;
    cout << solve(x) << endl;
  }
  return 0;
}
