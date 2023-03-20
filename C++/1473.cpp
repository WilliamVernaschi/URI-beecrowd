#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
   int l, c; 
  while(cin >> l >> c){
  vector <vector<int>> mat;
  mat.resize(l);
  for(int i = 0; i < l; i++){
    mat[i].resize(c);
  }
  for(int i = 0; i < l; i++){
    for(int j = 0; j < c; j++){
      cin >> mat[i][j];
    }
  }
  int tot=0;
  for(int i = 0; i < l; i++){
    for(int j = 0; j < c; j++){
      int cor_l = (mat[i][j]-1)/c;
      if(cor_l != i){
        swap(mat[i], mat[cor_l]);
        tot++;
        /*
        for(int u = 0; u < l; u++){
          for(int v = 0; v < c; v++){
            cout << mat[u][v] << " ";
          }
          cout <<endl;
        }
        cout << endl;
        */
      }
                } 
  }
  for(int i = 0; i < l; i++){
    for(int j = 0; j < c; j++){
      int cor_l = (mat[i][j]-1)/c;
      if(cor_l != i){
        swap(mat[i], mat[cor_l]);
        tot++;
        /*
        for(int u = 0; u < l; u++){
          for(int v = 0; v < c; v++){
            cout << mat[u][v] << " ";
          }
          cout <<endl;
        }
        cout << endl;
        */
      }
                } 
  }
  //cout << "acabei o primeiro com " << tot << endl;
  vector<vector<int>> transp;
  transp.resize(c);
  for(int i = 0; i < c; i++){
    transp[i].resize(l);
  }
  for(int i = 0; i < l; i++){
    for(int j = 0; j < c; j++){
      transp[j][i] = mat[i][j];
    }
  }
  for(int i = 0; i < c; i++){
    for(int j = 0; j < l; j++){
      int cor_col = (transp[i][j]-1)%c;
      //cout << cor_col << endl;
      //cout << t << endl;
            if(cor_col != i){
        //cout << "o " << transp[i][j] << " tá na coluna errada " << endl;
        //cout << "movendo da coluna " << i << " para " << cor_col << endl;
        swap(transp[i], transp[cor_col]);
        tot++;
      }
                    }
  } 
  for(int i = 0; i < c; i++){
    for(int j = 0; j < l; j++){
      int cor_col = (transp[i][j]-1)%c;
      //cout << cor_col << endl;
      //cout << t << endl;
            if(cor_col != i){
        swap(transp[i], transp[cor_col]);
        tot++;
      }
                    }
  } 
    for(int i = 0; i < c; i++){
    for(int j = 0; j < l; j++){
      mat[j][i] = transp[i][j];
    }
  }
  int t=1;
  bool breakout=false;
  for(int i = 0; i < l; i++){
    if(breakout) break;
    for(int j = 0; j < c; j++){
      if(breakout) break;
      if(mat[i][j] != t){
        cout << "*" << endl;
        breakout=true;
        break;
      //cout << mat[i][j] << " ";
      }
      t++;
          }
  }
  if(!breakout)
    cout << tot << endl;
  }
}
