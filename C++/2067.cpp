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
const int MAX=200+5;
int mat[MAX][MAX];
int sparse[__lg(MAX)+1][MAX][MAX];
int n, m;
void build(){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      sparse[0][i][j] = mat[i][j];
    }
  }
    for(int k = 1 ; k <= __lg(min(m, n)); k++){
    for(int i = 0; i + (1 << k) <= n; i++){
      for(int j = 0; j + (1 << k) <= m; j++){
        sparse[k][i][j] = min(min(sparse[k-1][i][j], sparse[k-1][i + (1 << (k-1))][j]), min             
      }
    }
  }
}
bool query(int l){
  int x=0;
  int k = __lg(l);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(i+l - (1 << k) >= n || j+l - (1 << k) >= m) continue;
            x = max(x, min(min(sparse[k][i][j], sparse[k][i+l - (1 << k)][j]), min(sparse[k][i][j             
    }
  }
  return x;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  int ans1 = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> mat[i][j];
      ans1 = max(ans1, mat[i][j]);
    }
  }
  build();
  int qq; cin >> qq;
  while(qq--){
    int q; cin >> q;
    if(q == 1){
      cout << (ans1 > 0 ? "yes" : "no") << endl;
    }
    else{
      cout << (query(q) ? "yes" : "no") << endl;
    }
  }
}
