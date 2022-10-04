#include <iostream>

using namespace std;

int main(){
  char c; string s;
  while(cin >> c >> s){
    if(c == '0' && s == "0") return 0;
    string res="";

    for(int i = 0; i < s.size(); i++){
      if(s[i] != c){
        res += s[i];
      }
    }
    int i = 0;
    while(res[i] == '0'){
      i++;
    }
    if(i == res.size()){
      cout << 0 << endl;
    }
    else{
      for(int j = i; j < res.size(); j++){
        cout << res[j];
      }
      cout << '\n';
    }

  }
  return 0;
  
}
