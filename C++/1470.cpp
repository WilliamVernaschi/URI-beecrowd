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
deque <int> fold(deque<int> &x, int p){
  deque <int> done;
  int r = p;
  int l = p-1;
  while(r < x.size() || l >= 0){
    if(l >= 0 && r < x.size()){
      done.push_front(x[l] + x[r]);
    }
    else if(r < x.size()){
      done.push_front(x[r]);
    }
    else{
      done.push_front(x[l]);
    }
    l--; r++;
  }
  return done;
}
deque <int> arr;
bool issolution(deque <int>& ok){
    if(ok.size() != arr.size()) return false;
  for(int i = 0; i < ok.size(); i++){
    if(arr[i] != ok[i]) return false;
  }
  return true;
}
bool solve(deque <int> &x){
  if(x.size() == 1){
    if(arr.size() == 1 && x[0] == arr[0]) return true;
    else return false;
  }
  if(issolution(x)){
    return true;
  }
  bool ok=false;
  for(int i = 1; i < x.size(); i++){
    deque <int> folded = fold(x, i);
    if(issolution(folded)){
      return true;
    }
    else{
      ok |= solve(folded);
    }
  }
  return ok;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int m;
  while(cin >> m){
    arr.clear();
    deque <int> tryme;
    for(int i = 0; i < m; i++){
      int x; cin >> x;
      tryme.PB(x);
    }
    int n; cin >> n;
    for(int i = 0; i < n; i++){
      int x; cin >> x;
      arr.PB(x);
    }
    deque <int> inv = fold(tryme, 0);
    if(solve(tryme) || solve(inv)){
      cout << "S" << endl;
    }
    else{
      cout << "N" << endl;
    }
  }
}
