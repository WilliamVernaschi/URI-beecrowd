#include<bits/stdc++.h>
using namespace std;
long long mypow(long long b, long long n){
  if(n == 0){
    return 1;
  }
  else if(n % 2 == 1){
    return b*mypow(b, n-1);
  }
  else{
    return mypow(b,n/2)*mypow(b,n/2);
  }
}
long long p(long long n){
  long long res=0;
  for(long long i = 1; i <= n; i++){
    res += i*9*mypow(10,i-1);
  }
  return res;
}
long long f(long long l, long long &resto, long long n){
  long long pn = p(n-1)+1;
  //cout << "pn = " << pn << endl;
  resto = (l - pn)%n;
  return (l-pn)/n + mypow(10, n-1);
}
int main(){
  long long k; cin >> k;
  long long l, r; cin >> l >> r;
  long long n=-1;
  for(long long i = 0; i < 17; i++){
    if(l > p(i) && l <= p(i+1)){
      n = i+1;
    }
  }
  if(n == -1) n = 18;
  if(l == 0) n = 1;
  long long res;
  long long form_n = f(l, res, n);
  string infi = to_string(form_n).substr(res, string::npos);
  for(long long i = form_n+1; infi.size() <= 2*(r-l); i++){
    infi += to_string(i);
  }
  //cout << res << endl;
  //infi = to_string(form_n).substr(res, string::npos) + infi;
  infi = infi.substr(0, r-l+1);
  //cout << infi << endl;
  string biggest="0", curr;
  k = min(k, (long long)infi.size());
  for(long long i = 0; i < infi.size() - k+1; i++){
    curr = infi.substr(i, k); 
    if(curr > biggest){
      biggest = curr;
    }
  }
  //cout << biggest << endl;
  cout << (stoll(biggest)) << endl;
}
