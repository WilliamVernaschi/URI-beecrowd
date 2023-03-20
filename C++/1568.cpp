#pragma GCC optimize("fast-math")
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
const int MAX=3e6+5;
//vector<ll> is_not_prime(MAX, 0);
bool is_not_prime[MAX];
vector<ll> primes;
void sieve(){
  for(int i = 2; i < MAX; i++){
    if(!is_not_prime[i]){
      primes.PB(i);
      for(int j = 2*i; j < MAX; j+=i){
        if(!is_not_prime[j]) is_not_prime[j] = i;
      }
    }
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  sieve();
  //clog << "sieve done" << endl;
  ll n;
  while(cin >> n){
    ll ans=1;
    if(n == 0){
      cout << 1 << endl;
      continue;
    }
    /*
    for(auto p : primes){
      if(p > sqrt(n)) break;
      if((n - ((p*(p+1))/2))%p == 0 && (n - p*(p+1)/2)/p + 1 >= 1){
        ans += n/p;
      }
    }
    */
        /*
    ll maxto = 1.5*sqrt(n);
    for(ll i = 1; i <= maxto; i++){
      if((n - ((i*(i+1))/2))%i == 0 && (n - i*(i+1)/2)/i + 1 >= 1){
        ans++;
      }
    }
    ll ans = 1;
    */
    unordered_map<ll, ll> pc;
    for(auto p : primes){
      if(p > 1.5*sqrt(n)) break;
      while(n%p == 0) {
        pc[p]++;
        n /= p;
      }
    }
    if(n > 1){
      pc[n]++;
    }
    for(auto [k, v] : pc){
      if(k != 2) ans *= (v+1);
    }
        cout << ans << endl;
  }
}
// Stuck? Answer these:
//
// Did I understand the problem correctly?
// Did I read the restrictions carefully? i.e: there is something like n*m < 2e5, when n <= 2e5 and m <= 2e5
// Should I be using long long instead of int somewhere?
// Should I be using double instead of int somewhere?
// Do in need to reset any values after a procedure?
// Is there a tricky pattern to be found? Try bruteforcing a solution to find it.
// No good ideas after around 2h? Try another problem / look up the solution
