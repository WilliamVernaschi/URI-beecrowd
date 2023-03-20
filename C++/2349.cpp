#include <iostream>
using namespace std;
void movesc(int* curr, int d, int n){
  if(*curr+d > n) *curr = 1;
  else if(*curr+d < 1) *curr = n;
  else *curr = *curr + d;
}
int main(){
  int n, c, d; cin >> n >> c >> d;
  int curr=1, tot=0, dir;
  for(int i = 0; i < c; i++){
    cin >> dir;
    if(curr == d) tot++;
    movesc(&curr, dir, n);
  }
  if(curr == d) tot++;
  cout << tot << endl;
  return 0;
}
