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
int park[1001];
int main(){
  FFIO;
  int comp, ev;
  while(cin >> comp >> ev){
    int ans=0;
    for(int u = 0; u < ev; u++){
      char type;
      int plate, sz;
      cin >> type;
      if(type == 'S'){
        cin >> plate;
        for(int i = 0; i < comp; i++){
          if(park[i] == plate){
            park[i] = 0;
          }
        }
      }
      else{
        cin >> plate >> sz;
        int space=0;
        for(int i = 0; i < comp; i++){
          if(park[i] == 0){
            space++;
            if(space == sz){
              for(int j = i-space+1; j <= i; j++){
                park[j] = plate;
              }
              ans+=10;
              break;
            }
          }
          else{
            space = 0;
          }
        }
      }
    }
    cout << ans << '\n';
    for(int i = 0; i < comp; i++) park[i] = 0;
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
