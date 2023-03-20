#include <iostream>
using namespace std;
int main(){
  int a, b; cin >> a >> b;
    for(int x=2; x <= 16; x = x<<1){
    for(int i=1,j=x; j <= 16; i+=x, j+=x){
      //cout << x << endl;
      //cout << i << " " << j << endl;
      if(a <= j && a >= i && b <= j && b >= i){
        switch(x){
          case 2:
            cout << "oitavas" << endl;
            break;
          case 4:
            cout << "quartas" << endl;
            break;
          case 8:
            cout << "semifinal" << endl;
            break;
          case 16:
            cout << "final" << endl;
            break;
        }
        return 0;
      }
    }
  }
}
