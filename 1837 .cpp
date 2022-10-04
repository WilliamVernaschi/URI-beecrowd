#include <iostream>
#include <cmath>

using namespace std;

int main(){
  int a, b; cin >> a >> b;
  for(int r = 0; r < abs(b); r++){
    if((a-r)%b == 0){
      cout << ((a-r)/b) << " " << r << endl;
    }
  }
  return 0;
}
