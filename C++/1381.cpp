#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define PMOD(n, m) ((((n) % (m)) + (m)) % (m))
#define debug(x) cerr << #x << " = " << x << endl;
#define debug2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl;
#define debug3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;
#define debug4(x, y, z, w) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #w << " = " << w << endl;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
const int INF=1e9+7;
// Stuck? Answer these:
//
// Did I understand the problem correctly?
// Did I read the restrictions carefully? i.e: there is something like n*m < 2e5, when n <= 2e5 and m <= 2e5
// Should I be using long long instead of int somewhere?
// Should I be using double instead of int somewhere?
// Do in need to reset any values after a procedure?
// Is there a tricky pattern to be found? Try bruteforcing a solution to find it.
// No good ideas after around 2h? Try another problem / look up the solution
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<ll> inv(1300031);
  vector<ll> modd(1300031);
  inv[1] = 1;
  modd[1] = 1;
  ll m = 1300031;
  for(int i = 2; i < m; i++){
    inv[i] = m - (m/i) * inv[m%i] % m;
    modd[i] = ((modd[i-1]%m)*(i%m)) % m;
  }
  for(int i = 2; i < m; i++){
    inv[i] = ((inv[i-1]%m) * (inv[i]%m))%m;
  }
  int t; cin >> t;
  while(t--){
    ll n, c; cin >> n >> c;
    if(n-1+c >= m){
      cout << 0 << endl;
    }
    else{
      cout << (((modd[(n-1)+c]*inv[n-1])%m)*inv[c])%m << endl;
    }
  }
}
