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
#define endl '\n'
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
const ll INF=2e9+7;
const ll INFLL=2e18;
struct item{
  ll segm=-INFLL, pfx=-INFLL, sfx=-INFLL, sum=0, l=0, r=1, sfx_start=0, pfx_end=1, size=1;
};
item seg[(1 << 18)]; // 2^17 > 1e5
struct interval{
  ll size, sum;
};
item NEUTRAL = {-INFLL, -INFLL, -INFLL, 0, 0, 1, 0, 1, 1};
struct segtree{
  ll size;
  void init(ll n){
    size = 1;
    while(size < n) size *= 2;
    //for(int i = 0; i < size*2; i++) seg[i] = NEUTRAL;
  }
  void build(vector<ll>&a, ll x, ll lx, ll rx){
    if(rx - lx == 1){
      if(lx < (ll)a.size()){
        seg[x].pfx = seg[x].sfx = seg[x].segm = seg[x].sum = a[lx];
        seg[x].l = seg[x].sfx_start = lx;
        seg[x].r = seg[x].pfx_end = lx+1;
        seg[x].size = 1;
      }
      return;
    }
    ll m = (lx+rx)/2;
    build(a, 2*x+1, lx, m);
    build(a, 2*x+2, m, rx);
    seg[x] = op(seg[2*x+1], seg[2*x+2]);
  }
  void build(vector<ll> &a){
    build(a, 0, 0, size);
  }
  item op(item a, item b){
    item ans;
    ans.sum = a.sum + b.sum;
        ans.segm = max(max(a.segm, b.segm), a.sfx + b.pfx);
    ll interv1 = a.r-a.l;
    ll interv2 = b.r-b.l;
    ll interv3 = b.pfx_end - a.sfx_start;
    ll sum1 = a.segm;
    ll sum2 = b.segm;
    ll sum3 = a.sfx + b.pfx;
    ans.size = -INF;
    if(ans.segm == sum1 && interv1 > ans.size){
      ans.size = interv1;
      ans.l = a.l;
      ans.r = a.r;
    }
    if(ans.segm == sum2 && interv2 > ans.size){
      ans.size = interv2;
      ans.l = b.l;
      ans.r = b.r;
    }
    if(ans.segm == sum3 && interv3 > ans.size){
      ans.size = interv3;
      ans.l = a.sfx_start;
      ans.r = b.pfx_end;
    }
        if(a.pfx > a.sum + b.pfx){
      ans.pfx = a.pfx;
      ans.pfx_end = a.pfx_end;
    }
    else{
      ans.pfx = a.sum + b.pfx;
      ans.pfx_end = b.pfx_end;
    }
      if(b.sfx > b.sum + a.sfx){
      ans.sfx = b.sfx;
      ans.sfx_start = b.sfx_start;
    }
    else{
      ans.sfx = b.sum + a.sfx;
      ans.sfx_start = a.sfx_start;
    }
        return ans;
  }
  item max_seg(ll l, ll r, ll x, ll lx, ll rx){
    if(lx >= l && rx <= r){
      return seg[x];
    }
    if(rx <= l || lx >= r){
      return NEUTRAL;
    }
    ll m = (lx+rx)/2;
    item s1 = max_seg(l, r, 2*x+1, lx, m);
    item s2 = max_seg(l, r, 2*x+2, m, rx);
    return op(s1, s2);
  }
  interval max_seg(ll l, ll r){
    item ans = max_seg(l, r, 0, 0, size);
    return {ans.r - ans.l, ans.segm};
  }
  void update(int idx, ll v, ll x, ll lx, ll rx){
    if(rx - lx == 1){
      seg[x].pfx = seg[x].sfx = seg[x].segm = seg[x].sum = v;
      seg[x].l = seg[x].sfx_start = idx;
      seg[x].r = seg[x].pfx_end = idx+1;
      seg[x].size = 1;
      //seg[x].l = seg[x].r = seg[x].pfx_end = seg[x].sfx_start = idx;
      return;
    }
    else{
      ll m = (lx+rx)/2;
      if(idx < m){
        update(idx, v, 2*x+1, lx, m);
      }
      else{
        update(idx, v, 2*x+2, m, rx);
      }
      // not commutative
      seg[x] = op(seg[2*x+1], seg[2*x+2]);
    }
  }
  void update(ll idx, ll v){
    update(idx, v, 0, 0, size);
  }
};
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t; cin >> t;
  while(t--){
    ll n; cin >> n;
    segtree s;
    s.init(n);
    vector<ll> a(n);
    for(ll i = 0; i < n; i++){
      cin >> a[i];
      //ll x; cin >> x;
      //s.update(i, x);
    }
    s.build(a);
    ll q; cin >> q;
    while(q--){
      ll l, r; cin >> l >> r;
      interval ans = s.max_seg(l-1, r);
      cout << ans.sum << ' ' << ans.size << '\n';
      //s.update(i, v);
      //ll ans = s.max_seg();
      //if(ans < 0) cout << 0 << endl;
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
