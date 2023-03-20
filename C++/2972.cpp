#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n; cin >> n;
  cout << (1ll << __builtin_popcountll(n)) << '\n';
  return 0;
}
