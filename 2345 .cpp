#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int v[4];
  int x, i=0;
  while(cin >> x){
    v[i]=x;
    i++;
  }
  sort(v, v+4);
  cout << abs((v[0] + v[3]) - (v[1] + v[2])) << endl;
  return 0;
}
