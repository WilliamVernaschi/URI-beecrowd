#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int issquare(int x){
  return (int)round(sqrt(x)) * (int)round(sqrt(x)) == x;
}


int main(){
  int t; cin >> t;
  int pegs[51] = {0};
  while(t--){
    int n; cin >> n;
    int j = 1;
    if(n == 1){
      cout << 1 << endl;
      continue;
    }
    bool finished=false;

    while(!finished){
      for(int i = 0; i <= n; i++){
        if(issquare(j + pegs[i]) || pegs[i] == 0){
            pegs[i] = j;
            j++;
            i = 0;
        }
        if(i == n){
          cout << j-1 << endl;
          finished=true;
        }
      }
    }
    memset(pegs, 0, 51*sizeof(int));
  }
  return 0;
}
