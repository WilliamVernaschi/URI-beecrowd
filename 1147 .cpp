#include <bits/stdc++.h>

using namespace std;

int main(){
  string cav;
  int t = 1;
  while(cin >> cav){
    if(cav == "0") break;
    map <string, vector<string>> tab;

    char dx_cav[8] = {1, 1, -1, -1, -2, -2, 2, 2}; 
    char dy_cav[8] = {2, -2, 2, -2, 1, -1, 1, -1}; 
    for(int i = 0; i < 8; i++){
      string pos;
      pos += cav[0]+dx_cav[i];
      pos += cav[1]+dy_cav[i];
      //cout << pos << endl;
      if(pos[0] <= '8' && pos[0] >= '1' && pos[1] >= 'a' && pos[1] <= 'h'){
        //cout << pos << endl;
        tab[cav].push_back(pos);
      }
      
    }
    string pawn;
    int tot=tab[cav].size();
    for(int j = 0; j < 8; j++){
      cin >> pawn;
      string atk1;
      string atk2;
      atk1 += pawn[0]-1;
      atk2 += pawn[0]-1;
      atk1 += pawn[1]+1;
      atk2 += pawn[1]-1;
      //cout << atk1 << endl;
      //cout << atk2 << endl;
      for(int i = 0; i < tab[cav].size(); i++){
        if(tab[cav][i] == atk1 || tab[cav][i] == atk2){
          tot--;
        }
      }
    }
    cout << "Caso de Teste #" << t << ": " << tot << " movimento(s)." << endl;
    t++;
  }
  return 0;
}
