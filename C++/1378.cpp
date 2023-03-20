#include <bits/stdc++.h>
using namespace std;
typedef long double ll;
struct point{
  ll x, y;
};
long double dist(point a, point b){
  return sqrtl((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
ll comb(int n, int k){
  ll res=1;
  if(k > n) return 0;
  for(int i=0; i < k; i++){
    res *= (n-i);
    res /= (i+1);
  }
  return res;
}
int main(){
  int n; 
  /*
  point p1, p2;
  p1.x = 1; p1.y = 1;
  p2.x = 100; p2.y = 100000;
  long double d1 = dist(p1, p2);
  p1.x++;
  long double d2 = dist(p1, p2);
  cout << d1 << " " << d2 << endl;
  cout << (d1 == d2) << endl;
  */
  while(cin >> n){
    if(n==0) break;
    vector <point> x;
    for(int i = 0; i < n; i++){
      point a;
      cin >> a.x >> a.y;
      x.push_back(a);
    }
    long double atob[n] = {0};
    int tot=0;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        atob[j] = dist(x[i], x[j]);
      }
      sort(atob, atob+n);
      /*for(int j = 0; j < n; j++){
        cout << atob[j] << endl;
      }
      */
      int uniq=1;
      for(int j = 0; j < n-1; j++){
        if(atob[j] == atob[j+1]) uniq++;
        else{
          tot += comb(uniq, 2);
          uniq=1;
        }
      }
      tot += comb(uniq, 2);
    }
    cout << tot << endl;
  }
    return 0;
}
