#include <iostream>
using namespace std;
int main(){
  int n1, n2, n3; cin >> n1 >> n2 >> n3;
  int min_tempo=10000000;
  min_tempo = min(2*n2 + 4*n3, min_tempo);
  min_tempo = min(2*n1 + 2*n3, min_tempo);
  min_tempo = min(4*n1 + 2*n2, min_tempo);
  cout << min_tempo << endl;
  return 0;
}
