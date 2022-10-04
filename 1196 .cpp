#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
  unordered_map<char, char> dic;
  dic = {{'W', 'Q'}, {'E', 'W'}, {'R', 'E'}, {'T', 'R'}, {'Y', 'T'}, {'U', 'Y'}, {'I', 'U'}, {'O', 'I'}, {'P', 'O'}, {'[', 'P'}, {']', '['}, {'\\', ']'}, {'S', 'A'}, {'A', 'A'}, {'D', 'S'}, {'F', 'D'}, {'H', 'G'}, {'G', 'F'}, {'J', 'H'}, {'K', 'J'}, {'L', 'K'},{';', 'L'}, {'\'', ';'}, {'X', 'Z'}, {'C', 'X'}, {'V', 'C'}, {'B', 'V'}, {'N', 'B'}, {'M', 'N'},{',', 'M'}, {'.', ','}, {'/', '.'}, {' ', ' '}, {'1', '`'}, {'2', '1'}, {'3', '2'}, {'5', '4'}, {'6', '5'}, {'7', '6'}, {'8', '7'}, {'9', '8'}, {'0', '9'}, {'-', '0'}, {'=', '-'}, {'4', '3'}, {'Z', 'Z'}};
  string s;
  while(getline(cin, s)){
    for(char c: s){
      printf("%c", dic[c]);
    }
    printf("\n");
  }
}