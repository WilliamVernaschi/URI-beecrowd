#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define PER(i,a,b) for(int i = a; i >= b; i--)
#define PMOD(n, m) ((((n) % (m)) + (m)) % (m))
#define debug(x) cerr << #x << " = " << x << endl;
#define debug2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
const int INF=1e9+7;
void lower(char &c){
  if(c >= 'A' && c <= 'Z') c += 32;
}
int main(){
  string s;
  set <string> words;
  while(cin >> s){
    string temps;
    for(int i = 0; i < s.size(); i++){
      lower(s[i]);
      if(s[i] >= 'a' && s[i] <= 'z'){
        temps += s[i];
      }
      else{
        if(temps.size() > 0) words.insert(temps);
        temps = "";
      }
      if(i == s.size()-1){
        if(temps.size() > 0) words.insert(temps);
      }
    }
  }
  for(string s : words){
    cout << s << endl;
  }
}
