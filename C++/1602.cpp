#ifdef ONLINE_JUDGE
  #define debug(x...)
#else
  #include "/mnt/d/dev/cp/debug.h"
#endif
#include <bits/stdc++.h>
using namespace std;
#define PMOD(n,m) ((((n) % (m)) + m) % m)
#define F first
#define S second
#define PB push_back
#define FFIO ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;
typedef pair<int, int> pii;
const int INF=1e9+7;
const ll INFLL=1e18+7;
const int MAX = (int)2e6+5;
vector<int> small_div(MAX, 0);
void sieve(){
  for(int i = 2; i < MAX; i++){
    if(!small_div[i]){
      for(int j = i+i; j < MAX; j+=i){
        small_div[j] = i;
      }
    }
  }
}
int main(){
  FFIO;
  sieve();
  vector<int> primes_pfx(MAX, 0);
  for(int i = 2; i < MAX; i++){
    if(small_div[i] == 0) primes_pfx[i]=1;
    primes_pfx[i] += primes_pfx[i-1];
  }
  int k;
  while(cin >> k){
    ll nc = 4;
    int i = 2;
    int ans=0;
    debug(primes_pfx[k]);
    for(int n = 4; i*i <= k;){
      nc = i*i;
      n = i*i;
      i++;
      debug(i, n);
      ll divs=1;
      while(small_div[n] != 0){
        int cnt=0;
        int thisdiv = small_div[n];
        while(small_div[n] == thisdiv){
          cnt++;
          n /= small_div[n];
          if(small_div[n] == 0){
            cnt++;
            n = 1;
          }
        }
        divs *= (cnt+1);
      }
      debug(nc, divs);
      debug(n);
      if(n != 1) divs *= 2;
      if(small_div[divs] == 0){
        ans++;
      }
    }
    debug(ans);
    cout << primes_pfx[k] + ans << endl;
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
