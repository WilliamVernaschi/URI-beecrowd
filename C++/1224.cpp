#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int MAX = 10005;
ll prev1[MAX];
ll prev2[MAX];
ll curr[MAX];
ll c[MAX];
int n;
void solve(int k){
  for(int i = 0; i < k; i++){
    curr[i] = max(c[i] + min(prev2[i+2], prev2[i+1]), c[i+(n-k)] + min(prev2[i], prev2[i+1]))
  }
  for(int i = 0; i < k+2; i++){
    prev2[i] = prev1[i];
    prev1[i] = curr[i];
  }
}
int main(){
  while(cin >> n){
    for(int i = 0; i < n; i++) cin >> c[i];
    if(n == 2){
      cout << max(c[0], c[1]) << endl;
      continue;
    }
      for(int i = 0; i < n; i++){
      prev2[i] = c[i];
      if(i+1 < n)
        prev1[i] = max(c[i], c[i+1]);
    }
    for(int i = n-2; i >= 1; i--){
      solve(i);
    }
    cout << curr[0] << endl;
  }
}
