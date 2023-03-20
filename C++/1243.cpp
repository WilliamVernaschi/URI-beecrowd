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
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string inp;
  while(getline(cin, inp)){
    int len=0, words=0;
    istringstream iss(inp);
    string s;
    while(iss >> s){
      bool ok=true;
      for(int i = 0; i < s.size(); i++){
        if(!(('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z') || (s[i] == '.' &&   
          ok = false;
          break;
        }
      }
      ok &= (s != ".");
      if(ok){
        len += s.size() - (s[s.size()-1] == '.');
        words++;
      }
    }
    if(words == 0 || (len/words <= 3)){
      cout << 250 << endl;
    }
    else if(len/words <= 5){
      cout << 500 << endl;
    }
    else{
      cout << 1000 << endl;
    }
  }
}
