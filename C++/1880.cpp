#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool is_palin(vector <int> &x){
  for(int i = 0, j=x.size()-1; i <= j; i++, j--){
    if(x[i] != x[j]) return false;
  }
  return true;
}
void is_pal_bases(ll n){
  vector <int> valid_palins;
  bool none=true;
  vector <int> resps;
  for(int i = 2; i <= 16; i++){
    ll copy_n = n;
    vector <int> x;
    while(copy_n){
      x.push_back(copy_n%i);
      copy_n /= i;
    }
    if(is_palin(x) || n == 0){
      none=false;
      resps.push_back(i);
    }
  }
  if(none){
    cout << -1 << '\n';
  }
  else{
    for(int i = 0; i < resps.size()-1; i++){
      cout << resps[i] << " ";
    }
    cout << resps[resps.size()-1] << endl;
  }
}
int main(){
  int t; cin >> t;
  while(t--){
      ll n; cin >> n;
    is_pal_bases(n);
  }
}
