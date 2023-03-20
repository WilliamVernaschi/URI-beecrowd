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
struct segtree{
  int size;
  vector<int> seg;
  void init(int n){
    size = 1;
    while(size < n){
      size *= 2;
    }
    seg.assign(2*size, 1);
  }
  int query(int l, int r, int x, int lx, int rx){
    if(lx >= l && rx <= r) return seg[x];
    if(rx <= l || lx >= r) return 1;
    int m = (lx+rx)/2;
    int s1 = query(l, r, 2*x+1, lx, m);
    int s2 = query(l, r, 2*x+2, m, rx);
    return s1*s2;
  }
  int query(int l ,int r){
    return query(l, r, 0, 0, size);
  }
  void update(int idx, int v, int x, int lx, int rx){
    if(rx - lx == 1){
      seg[x] = v;
      return;
    }
        int m = (lx+rx)/2;
    if(idx < m) update(idx, v, 2*x+1, lx, m);
    else update(idx, v, 2*x+2, m, rx);
    seg[x] = seg[2*x+1]*seg[2*x+2];
  }
  void update(int idx, int v){
    update(idx, v, 0, 0, size);
  }
};
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, q;
  while(cin >> n >> q){
    segtree s;
    s.init(n);
    for(int i =0 ; i < n; i++){
      int x; cin >> x;
      if(x > 0) x = 1;
      else if(x < 0) x = -1;
      else x = 0;
      s.update(i, x);
    }
    while(q--){
      char type; cin >> type;
      if(type == 'C'){
        int idx, x; cin >> idx >> x;
        if(x > 0) x = 1;
        else if(x < 0) x = -1;
        else x = 0;
        s.update(idx-1, x);
      }
      else{
        int l, r; cin >> l >> r;
        int ans = s.query(l-1, r);
        if(ans == 0) cout << 0;
        else if(ans == 1) cout << '+';
        else cout << '-';
      }
    }
    cout << endl;
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
