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
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, q; 
  while(cin >> n >> q){
    if(n+q == 0) break;
    int arr[n+1];
    int r[n+2] = {0};
    int l[n+2] = {0};
    bool done[n+2] = {0};
    for(int i = 1; i <= n; i++) arr[i] = 1;
    for(int i = 1; i <= n; i++) l[i] = i-1;
    for(int i = 1; i <= n; i++) l[i] = i+1;
    l[1] = r[n] = -1;
    done[0] = 0;
    done[n+1] = 0;
    while(q--){
      int a, b; cin >> a >> b;
      /*
      s[a].l = s[a-1].l;
      s[b].r = s[b+1].r;
      */
      done[a] = done[b] = 1;
      int la = a-1;
      int rb = b+1;
      while(done[la]){
        la = l[la];
        l[a] = la;
      }
      l[a] = la;
      while(done[rb]){
        rb = r[rb];
        r[b] = rb;
      }
      r[b] = rb;
      l[b] = la;
      r[a] = rb;
      if(la == 0) cout << '*' << " ";
      else cout << la << " ";
      if(rb == n+1) cout << '*' << endl;
      else cout << rb << endl;
         }
    cout << "-\n";
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
