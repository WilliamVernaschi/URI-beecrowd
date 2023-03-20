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
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int n;
int mp[105][105];
bool valid(int i, int j){
  return i>=0 && j>=0 && i < n && j < n;
}
int letcode(char d){
  if('a' <= d && d <= 'z'){
    d -= 'a';
  }
  else{
    d -= 'A';
  }
  return (int)d;
}
bool islower(char d){
  return ('a' <= d && d <= 'z');
}
int dist[105][105];
vector<int> combs;
int ans=INF;
void bfs(){
  queue<pair<int, int>> q;
  q.push({0, 0});
  if((bool)combs[letcode(mp[0][0])] != (bool)islower(mp[0][0])) return;
  dist[0][0] = 1;
  while(!q.empty()){
    pair<int,int> v = q.front();
    q.pop();
    for(int k = 0; k < 4; k++){
      int newi = v.F+dx[k];
      int newj = v.S+dy[k];
      if(!valid(newi, newj) || dist[newi][newj]) continue;
      int let = mp[newi][newj];
      if(((bool)islower(let) != (bool)combs[letcode(let)])) continue;
      dist[newi][newj] = dist[v.F][v.S] + 1;
      q.push({newi, newj});
    }
  }
  if(dist[n-1][n-1] > 0)
    ans = min(ans, dist[n-1][n-1]);
  memset(dist, 0, sizeof(dist));
}
void solve(int idx){
  if(idx == 10){
    bfs();
    /*
    for(int x : combs) cout << x << " ";
    cout << endl;
    return;
    */
  }
  else{
    combs.PB(0);
    solve(idx+1);
    combs.pop_back();
    combs.PB(1);
    solve(idx+1);
    combs.pop_back();
  }
}
int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    string s; cin >> s;
    for(int j = 0; j < n; j++){
      mp[i][j] = s[j];
    }
  }
  solve(0);
  if(ans == INF){
    cout << -1 << endl;
  }
  else cout << ans << endl;
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
