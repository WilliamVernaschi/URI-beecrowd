#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(int x){
  for(int i = 2; i <= sqrt(x); i++){
    if(x % i == 0) return false;
  }
  return true;
}

int main(){
  int n; cin >> n;
  for(int i = n; i >= 2; i--){
    if(is_prime(i)){
      cout << i << endl;
      break;
    }
  }

  return 0;
}
