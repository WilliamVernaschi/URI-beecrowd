#include <iostream>
using namespace std;
int mdc(int a, int b){
  if(b == 0) return a;
  return mdc(b, a%b);
}
int main(){
  int partint, partdec;
  scanf("%d.%d", &partint, &partdec);
  int r = partint*100 + partdec;
  cout << 36000/mdc(36000, r) << endl;
  return 0;
}
