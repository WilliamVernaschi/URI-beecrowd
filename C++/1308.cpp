#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
int main(){
  ll n, x; cin >> n;
  while(n--){
    cin >> x;
    cout << (int)((-1 + sqrt(1+8*x))/2) << endl;
  }
}
