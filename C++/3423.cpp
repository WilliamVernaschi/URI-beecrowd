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
char mat[210][210];
int n, m;
pair<pair<string, string>, char> ans;
map<char, vector<pii>> posis;
bool solve(string &s, pair<int, int> pos, char d, int idx){
  int i = pos.F;
  int j = pos.S;
  if(i < 0 || j < 0 || i >= n || j >= m) return false;
  if(mat[i][j] == '1'){
    if(d == 'U') d = 'R';
    else if(d == 'L') d = 'D';
  }
  else if(mat[i][j] == '2'){
    if(d == 'R') d = 'D';
    else if(d == 'U') d = 'L';
  }
  else if(mat[i][j] == '3'){
    if(d == 'D') d = 'L';
    else if(d == 'R') d = 'U';
  }
  else if(mat[i][j] == '4'){
    if(d == 'L') d = 'U';
    else if(d == 'D') d = 'R';
  }
  else if(mat[i][j] != s[idx]) return false;
  else{
    if(idx == s.size() - 1){
      return true;
    }
  }
  if((mat[i][j] >= 'A' && mat[i][j] <= 'Z')){
    idx++;
  }
  if(d == 'U')
    return solve(s, {i-1, j}, d, idx);
    else if(d == 'D')
    return solve(s, {i+1, j}, d, idx);
    else if(d == 'L')
    return solve(s, {i, j-1}, d, idx);
  else
    return solve(s, {i, j+1}, d, idx);
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    cin >> mat[i];
    for(int j = 0; j < m; j++){
      if(mat[i][j] >= 'A' && mat[i][j] <= 'Z'){
        posis[mat[i][j]].PB({i, j});
      }
    }
  }
    int q; cin >> q;
  for(int i = 0; i < q; i++){
    string s; cin >> s;
    ans = {{"9999999999999999", "9999999999999999"}, 'Z'};
    pair<pair<string, string>, char> oans = {{"9999999999999999", "9999999999999999"}, 'Z'
    for(pii x : posis[s[0]]){
      //debug2(to_string(x.F), to_string(x.S));
      if(solve(s, x, 'U', 0)){
        ans = min(ans, {{to_string(x.F+1), to_string(x.S+1)}, 'U'});
      }
      if(solve(s, x, 'D', 0)){
        ans = min(ans, {{to_string(x.F+1), to_string(x.S+1)}, 'D'});
      }
      if(solve(s, x, 'R', 0)){
        ans = min(ans, {{to_string(x.F+1), to_string(x.S+1)}, 'R'});
      }
      if(solve(s, x, 'L', 0)){
        ans = min(ans, {{to_string(x.F+1), to_string(x.S+1)}, 'L'});
      }
    }
    if(ans != oans){
      cout << ans.F.F << " " << ans.F.S << " " << ans.S << endl;
    }
    else{
      cout << ":(" << endl;
    }
  }
}
