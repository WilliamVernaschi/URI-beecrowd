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
  int n; cin >> n;
  int g;
  vector<int> points(n+1, 0);
  vector<int> goals(n+1, 0);
  vector<int> runner_ups(n+1, 0);
  int most=-1;
  while(cin >> g){
    if(!g) break;
    for(int i = 0; i < g; i++){
      int t1, s1, t2, s2; cin >> t1 >> s1 >> t2 >> s2;
      goals[t1] += s1;
      goals[t2] += s2;
      if(s1 > s2){
        points[t1]+=3;
      }
      else if(s2 > s1){
        points[t2]+=3;
      }
      else{
        points[t1]+= 1;
        points[t2]+= 1;
      }
    }
    int largest=1;
    for(int i = 1; i <= n; i++){
      if(points[i] > points[largest] || (points[i] == points[largest] && goals[i] > goals[            
        largest = i;
      }
    }
    int prev=largest;
    if(largest == 1){
      largest = 2;
    }
    else{
      largest = 1;
    }
    for(int i = 1; i <= n; i++){
      if(i == prev) continue;
      if(points[i] > points[largest] || (points[i] == points[largest] && goals[i] > goals[            
        largest = i;
      }
    }
    runner_ups[largest]++;
    most = max(most, runner_ups[largest]);
    fill(points.begin(), points.end(), 0);
    fill(goals.begin(), goals.end(), 0);
            }
  if(most == runner_ups[1]){
    cout << "Y" << endl;
  }
  else{
    cout << "N" << endl;
  }
}
