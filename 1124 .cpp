#include <iostream>
#include <cmath>

using namespace std;

int main(){
  int w, l, r1, r2; 
  while(cin >> w >> l >> r1 >> r2){
    if(w == 0) break;
    //cout << sqrt( ((r1 - (w-r2))*(r1 - (w-r2))) + ((r1 - (l-r2))*(r1 - (l-r2)) )) << endl;
    if(2*r1 <= min(w, l) && 2*r2 <= min(w, l) && ((max(w, l) >= 2*r1+2*r2 && min(w, l) >= max(2*r1,2*r2)) || (sqrt( ((r1 - (l-r2))*(r1 - (l-r2))) + ((r1 - (w-r2))*(r1 - (w-r2)) )) >= r1+r2)))
      cout << "S" << endl;
    else
      cout << "N" << endl;
  }
  
  

  return 0;
}
