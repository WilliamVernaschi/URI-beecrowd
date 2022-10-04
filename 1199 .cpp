#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

string dec2hex(long long x){
  if(x == 0) return "0x0";
  string res;
  while(x > 0){
    long long rem = x%16;
    x /= 16;

    if(rem > 9) res += (char)(rem-10)+'A';
    else        res += (char)(rem)+'0';
  }
  res += "x0";
  reverse(res.begin(), res.end());
  return res;
}


long long hex2dec(string x){
  long long res=0;
  for(long long i = x.size() - 1; i >= 2; i--){
    long long num;
    if(x[i] >= 'A' && x[i] <= 'Z') num = (long long)(x[i]-'A')+10;
    else if(x[i] >= 'a' && x[i] <= 'z') num = (long long)(x[i]-'a')+10;
    else            num = (x[i]-'0');
    //cout << x.size()-i-1 << " " << num << endl;
    
    res += pow(16,x.size()-i-1)*num;
  }
  return res;
}

int main(){
  string t;
  while(cin >> t){
    long long intt = stol(t);
    if(intt < 0) return 0;
    if(t.size() >= 2 && t[1] == 'x') cout << hex2dec(t) << endl;
    else cout << dec2hex(intt) << endl;
  }
    
}
