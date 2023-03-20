#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree <int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update> indexed_set;
#define index_value find_by_order
#define value_index order_of_key
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define PER(i,a,b) for(int i = a; i >= b; i--)
#define PMOD(n, m) ((((n) % (m)) + (m)) % (m))
#define debug(x) cerr << #x << " = " << x << endl;
#define debug2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
const int INF=1e9+7;
int next_idx(int curr, int k, int ssize){
  int ans = (curr+k)%(ssize-1);
  if(ans > curr) ans--;
  return ans;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  int i = 1;
  while(t--){
    indexed_set s;
    int n, k; cin >> n >> k;
    for(int i = 1; i <= n; i++){
      s.insert(i);
    }
    int curr = (k-1)%n;
    int next_p;
    while(n > 1){
      if(curr == n-1)
        next_p = 0;
      else
        next_p = curr;
      s.erase(*s.index_value(curr));
      n--;
      curr = (next_p+(k-1))%n;
    }
    cout << "Case " << i << ": " << *s.index_value(0) << endl;
    i++;
  }
}
