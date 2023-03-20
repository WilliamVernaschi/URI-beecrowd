#include <iostream>
using namespace std;
int main(){
  int n;
  int caso=1;
  while(cin >> n){
    int res = n*(n+1)/2 + 1;
    cout << "Caso " << caso << ": " << res << " numero";
    if(res > 1)
      cout << "s";
    cout << '\n';
    if(n > 0) cout << "0" << " ";
    else cout << "0";
    for(int i = 0; i <= n; i++){
      for(int j = 0; j < i; j++){
        if(i < n || j < i-1){
          cout << i << " ";
        }
        else{
          cout << i;
        }
      }
    }
    cout << "\n\n";
    caso++;
  }
  return 0;
}
