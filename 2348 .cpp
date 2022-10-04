#include <iostream>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

bool comp(int a, int b){
  return a > b;
}

const double PI=3.14159265359;

int main(){
  int n; cin >> n;
  int quals[n];
  for(int i = 0; i < n; i++){
    cin >> quals[i];
  }
  sort(quals, quals+n, comp);
  int optimal[n];
  int inserted=0;
  int beg=0, end=n-1;
  while(inserted < n){
    optimal[beg] = quals[inserted];
    inserted++;
    if(inserted == n) break;
    optimal[end] = quals[inserted];
    inserted++;
    beg++;
    end--;
  }
  double res = 0;
  for(int i = 0; i < n-1; i++){
    res += ((optimal[i]*optimal[i+1])/2.0);
  }
  res += (optimal[0]*optimal[n-1])/2.0;

  res *= sin(2*PI/n);
  cout << fixed << setprecision(3) << res << endl;
  return 0;
}
