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
  vector<pair<int, int>> seg;
  int size;
  pair<int, int> op(pair<int, int> a, pair<int, int> b){
    pair<int, int> ans;
    ans.F = max(a.F, b.F);
    ans.S = min(a.S, b.S);
    return ans;
  }
  void init(int n){
    size = 1;
    while(size < n) size *= 2;
    seg.assign(2*size, make_pair(-INF, INF));
  }
  void build(vector<int> &a, int x, int lx, int rx){
    if(rx - lx == 1){
      if(lx < (int)a.size()) seg[x] = {a[lx], a[lx]};
      return ;
    }
    int m = (lx+rx)/2;
    build(a, 2*x+1, lx, m);
    build(a, 2*x+2, m, rx);
    seg[x] = op(seg[2*x+1], seg[2*x+2]);
  }
  void build(vector<int> &arr){
    build(arr, 0, 0, size);
  }
  void update(int idx, int v, int x, int lx, int rx){
    if(rx - lx == 1){
      seg[x] = {v, v};
      return;
    }
    int m = (lx+rx)/2;
    if(idx < m){
      update(idx, v, 2*x+1, lx, m);
    }
    else{
      update(idx, v, 2*x+2, m, rx);
    }
    seg[x] = op(seg[2*x+1], seg[2*x+2]);
  }
  void update(int idx, int v){
    update(idx, v, 0, 0, size);
  }
  pair<int, int> query(int l, int r, int x, int lx, int rx){
    if(lx >= l && rx <= r) return seg[x];
    if(rx <= l || lx >= r) return {-INF, INF};
    int m = (lx+rx)/2;
    pair<int, int> s1 = query(l, r, 2*x+1, lx, m);
    pair<int, int> s2 = query(l, r, 2*x+2, m, rx);
    return op(s1, s2);
  }
  pair<int, int> query(int l, int r){
    return query(l, r, 0, 0, size);
  }
};
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  while(cin >> n){
    segtree s;
    s.init(n);
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
      cin >> arr[i];
    }
    s.build(arr);
    int q; cin >> q;
    while(q--){
      int t; cin >> t;
      if(t == 1){
        int idx, newp; cin >> idx >> newp;
        s.update(idx-1, newp);
      }
      else{
        int l, r; cin >> l >> r;
        pair<int, int> ans = s.query(l-1, r);
        cout << ans.F - ans.S << '\n';
      }
    }
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
