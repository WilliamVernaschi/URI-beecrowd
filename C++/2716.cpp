#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int MAX=300005;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int possible[MAX];
  int n;
  while(cin >> n){
    int vals[155];
    int sumall=0;
    for(int i = 2; i <= n+1; i++){
      cin >> vals[i];
      sumall+= vals[i];
    }
    int closest = 1000000000;
    possible[0] = 1;
    for(int i = 2; i <= n+1; i++){
      for(int j = 0; j <= sumall; j++){
        if(possible[j] && possible[j] < i ){
          possible[j+vals[i]] = i;
        }
      }
    }
            int ans=0;
    for(int i = 0; i < sumall; i++){
      //cout << possible[i] << " ";
      if(possible[i] && (abs(i-sumall/2) < closest)){
        closest = abs(i-sumall/2);
        ans = i;
      }
    }
    //cout << endl;
    cout << abs(2*ans - sumall)  << endl;
    memset(possible, 0, MAX*sizeof(int));
  }
}
