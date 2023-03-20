#include <iostream>
using namespace std;
int main(){
  int nw, nl, nc;
  while(cin >> nw >> nl >> nc){
    int curr_char_count = -1, curr_page_count=1, curr_line_count=1;
    for(int i = 0; i < nw; i++){
      string next_word; cin >> next_word;
      if(curr_char_count + next_word.size() + 1 > nc){
        curr_char_count = next_word.size();
        if(curr_line_count + 1 > nl){
          curr_line_count = 1;
          curr_page_count++;
        }
        else curr_line_count++;
      }
      else curr_char_count += next_word.size() + 1;
      //cout << next_word << " chars: " << curr_char_count
      //  << " lines: " << curr_line_count << " pages: " << curr_page_count << endl;
    }
    cout << curr_page_count << endl;
  }
  return 0;
}
/*
Se mana Piedade tem |
casado com Quincas  |
Borba apens me daria|
uma esperanca       |
colateral           |
*/
