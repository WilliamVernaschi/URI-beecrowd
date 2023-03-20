#include <iostream>
#include <unordered_map>
using namespace std;
int main(){
  unordered_map<char, char> dic;
  dic = {{'W', 'Q'}, {'E', 'W'}, {'R', 'E'}, {'T', 'R'}, {'Y', 'T'}, {'U', 'Y'}, {'I', 'U'}                                                                            
  string s;
  while(getline(cin, s)){
    for(char c: s){
      printf("%c", dic[c]);
    }
    printf("\n");
  }
}
