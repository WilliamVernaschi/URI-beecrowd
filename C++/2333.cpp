#include <iostream>
using namespace std;
#define FFIO ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){
  FFIO;
  int n; cin >> n;
  int tot_sum=0;
  int maxs=0, mins=0, curr=0, curr2=0;
  while(n--){
    int x; cin >> x;
    tot_sum += x;
    if(curr + x > 0){
      maxs = max(maxs, curr+x);
      curr += x;
    }
    else{
      curr = 0;
    }
    if(curr2 - x > 0){
      mins = max(mins, curr2-x);
      curr2 -= x;
    }
    else{
      curr2 = 0;
    }
  }
  cout << max(maxs, tot_sum + mins) << '\n';
}
