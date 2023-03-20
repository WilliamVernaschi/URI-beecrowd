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
int a, b, c, d;
bool invalid(int x){
  return x%a != 0 || x%b == 0 || d%x == 0;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  while(cin >> a >> b >> c >> d){
    vector<int> v;
    for(int i = 1; i*i <= c; i++){
      if(c%i == 0){
        v.PB(i);
        v.PB(c/i);
      }
    }
    v.erase(remove_if(v.begin(), v.end(), invalid), v.end());
    /*
    for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;
    for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;
    */
    sort(v.begin(), v.end());
    if(v.size() == 0) cout << -1 << endl;
    else cout << v[0] << endl;
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
