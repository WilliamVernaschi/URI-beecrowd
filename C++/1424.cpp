#include <bits/stdc++.h>
using namespace std;
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
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,m;
  while(cin >> n >> m){
    map<int, vector<int>> mp;
    for(int i = 0; i < n; i++){
      int x; cin >> x;
      mp[x].PB(i);
    }
    for(int i = 0; i < m; i++){
      int x, y; cin >> y >> x;
      if(mp[x].size() < y){
        cout << 0 << endl;
      }
      else{
        cout << mp[x][y-1]+1 << endl;
      }
    }
  }
}
