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
//
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // set -> 2 2 2
  // pair -> 2 3 2
  // no-pair -> 1 2 3
  //
  // set > pair > no-pair
  // set1 > set2 <=> max(set1) > max(set2)
  int s[3];
  while(cin >> s[0] >> s[1] >> s[2]){
    if(s[0]+s[1]+s[2] == 0) break;
    sort(s, s+3);
    int ans[3];
    int a = s[0], b = s[1], c= s[2];
    if(a == b && b == c){
      if(a < 13){
        ans[0] = a+1;
        ans[1] = b+1;
        ans[2] = c+1;
      }
      else{
        ans[0] = -1;
      }
    }
    else if(a == b || b == c){
      if(a == b){
        if(c < 13){
          if(a == 13 && b == 13 && c == 12){
            ans[0] = 1;
            ans[1] = 1;
            ans[2] = 1;
          }
          else if(c+1 != b){
            ans[0] = a;
            ans[1] = b;
            ans[2] = c+1;
          }
          else{
            ans[0] = a;
            ans[1] = b;
            ans[2] = c+2;
          }
        }
        else{
          ans[0] = a+1;
          ans[1] = b+1;
          ans[2] = 1;
        }
      }
      else{
        if(a < 13){
          if(a == 12 && b == 13 && c == 13){
            ans[0] = 1;
            ans[1] = 1;
            ans[2] = 1;
          }
          else if(a+1 != b){
            ans[0] = a+1;
            ans[1] = b;
            ans[2] = c;
          }
          else{
            ans[0] = a+2;
            ans[1] = b;
            ans[2] = c;
          }
        }
        else{
          ans[0] = 1;
          ans[1] = b+1;
          ans[2] = c+1;
        }
      }
    }
    else{
      ans[0] = 1;
      ans[1] = 1;
      ans[2] = 2;
    }
    if(ans[0] == -1){
      cout << '*' << endl;
    }
    else{
      sort(ans, ans+3);
      cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
    }
  }
  }
