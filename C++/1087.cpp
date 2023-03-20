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
  int x, y, i, j; 
  //int cnt=0;
  while(cin >> x >> y >> i >> j){
    //cnt++;
    if(x+y+i+j == 0) break;
    int ans=0;
    if(i == x && y == j){
      cout << 0 << endl;
      continue;
    }
    bool diag = abs(x-i) == abs(y-j);
    bool row = i == x;
    bool col = j == y;
    if(diag || row || col){
      cout << 1 << endl;
    }
        else{
      cout << 2 << endl;
    }
    /*
    if(cnt == 8){
      cout << endl;
      cnt=0;
    }
    */
  }
}
