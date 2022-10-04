#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int j[4], tot=0, open_at = 0, close_at = 0;

  cin >> j[0] >> j[1] >> j[2]; j[3] = 600;
  sort(j, j+4);

  for(int i = 0; i < 4; i++){
    open_at = j[i];
    if(open_at - close_at > 0) tot += (open_at - close_at)*100;
    close_at = open_at + 200;
  }

  cout << tot << endl;
  return 0;
}
