#include <iostream>
using namespace std;
int main(){
  string n; cin >> n;
  int som_digitos = 0;
  for(int i = 0; i < n.size(); i++){
    som_digitos += (n[i] - '0');
  }
  if(som_digitos % 3 == 0){
    cout << 0 << endl;
  }
  else if(som_digitos % 3 == 1){
    cout << 1 << endl;
  }
  else{
    cout << 2 << endl;
  }
  return 0;
}
