#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;
string A[20], B[20];
bool comp(string a, string b){
  return a.size() < b.size();
}
int n1, n2;
map <pair<string, string*>, int> dp;
int solve(string str, string* S, int S_size){
  pair<string, string*> p = {str, S};
  if(dp[p] == -1 || dp[p] == 1) return (dp[p] == 1);
  if(dp[p] == 2) return false;
  /*cout << " procurando " << str << " no conjunto ";
  if(S == A)
    cout << "A" << '\n';
  else
    cout << "B" << '\n';
  */
  dp[p] = 2;
    for(int i = 0; i < S_size; i++){
    int num_letters_compared = min(str.size(), S[i].size());
    if(S[i].substr(0, num_letters_compared) == str.substr(0, num_letters_compared)){
      //cout << "ué: " << str << " " << S[i] << endl;
      if(S[i] == str){
        dp[p] = 1;
        break;
      }
      else if(S[i].size() < str.size()){
        if(solve(str.substr(num_letters_compared, str.size()), S, S_size) == 1)
          dp[p] = 1;
      }
      else{
        string* other_set;
        int size_other_set;
        if(S == A){
          other_set = B;
          size_other_set = n2;
        }
        else{
          other_set=A;
          size_other_set=n1;
        }
        if(solve(S[i].substr(num_letters_compared, S[i].size()), other_set, size_other_set) == 
          dp[p] = 1;
              }
    }
  }
  if(dp[p] == 2){
    dp[p] = -1;
  }
  return dp[p];
}
int main(){
  while(cin >> n1 >> n2){
    int new_n2=0;
    dp.clear();
    string empty_s="";
    fill_n(A, 20, empty_s);
    fill_n(B, 20, empty_s);
    for(int i = 0; i < n1; i++)
      cin >> A[i];
    for(int i = 0; i < n2; i++){
      cin >> B[i];
    }
    bool repeated=false;
    for(int i = 0; i < n2; i++){
      if(find(A, A+n1, B[i]) != A+n1){
        repeated=true;
        break;
      }
    }
    if(repeated){
      cout << "S" << '\n';
      continue;
    }
        bool solved = false;
    for(int i = 0; i < n1 && !solved; i++){
      solved |= (solve(A[i], B, n2) == 1);
    }
    for(int i = 0; i < n2 && !solved; i++)
      solved |= (solve(B[i], A, n1) == 1);
        if(solved) cout << "S" << '\n';
    else cout << "N" << '\n';
  }
  return 0;
}
