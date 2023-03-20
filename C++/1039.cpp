#include <iostream>
#include <cmath>
using namespace std;
int main(){
  int R, x1, y1, r, x2, y2;
  while(cin >> R >> x1 >> y1 >> r >> x2 >> y2){
    if(sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)) <= R - r)
      cout << "RICO" << endl;
        else
      cout << "MORTO" << endl;
      }
}
