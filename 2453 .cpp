#include <iostream>

using namespace std;

int main(){
  string s, next; cin >> s;
  do{
    
    for(int i = 0; i < s.size(); i+=2){
      cout << s[i+1];
    }
    if(cin >> next){
      cout << " ";
      s = next;
    }
    else
      break;
    

  }while(true);
  cout << '\n';
  return 0;
}
