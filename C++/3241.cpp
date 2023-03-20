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
  int t; cin >> t;
  while(t--){
    string s; cin >> s;
    for(int i = 0; i < s.size(); i++){
      if(s[i] == '+'){
        cout << stoi(s.substr(0, i)) + stoi(s.substr(i+1, string::npos)) << endl;
        break;
      }
      if(i == s.size() - 1){
        cout << "skipped" << endl;
      }
    }
  }
}
