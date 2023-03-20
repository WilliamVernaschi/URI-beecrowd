#include <iostream>
using namespace std;
int main(){
    string a, b;
  while(cin >> a >> b){
    if(a == "0" && b == "0") break;
    int tam = max(a.size(), b.size());
    if(a.size() > b.size()){
      b = string(a.size() - b.size(), '0') + b;
    }
    else{
      a = string(b.size() - a.size(), '0') + a;
    }
    //cout << a << " " << b << endl;
    int subiu=0, carries=0;
    for(int i = tam - 1; i >= 0; i--){
      int res = a[i] - '0' + b[i] - '0' + subiu;
      subiu = res > 9; 
      //cout << a[i] << " " << b[i] << endl;
      carries += subiu;
    }
           if(!carries){
      cout << "No carry operation." << '\n';
    }
    else if(carries == 1){
      cout << "1 carry operation." << '\n';
    }
    else{
      cout << carries << " carry operations." << '\n';
    }
  }
  return 0;
}
