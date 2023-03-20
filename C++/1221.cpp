#include <iostream>
#include <cmath>
using namespace std;
int main(){
  int n; cin >> n;
  while(n--){
    int x, isprime=1; cin >> x;
    for(int i = 2; i <= sqrt(x); i++){
      if(x % i == 0){
        isprime=0;
        break;
      }
    }
    if(!isprime || x == 1)
      cout << "Not Prime" << '\n';
    else if(x == 2)
      cout << "Prime" << '\n';
    else
      cout << "Prime" << '\n';
          }
  return 0;
}
