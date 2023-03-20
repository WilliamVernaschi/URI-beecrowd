#include <bits/stdc++.h>
using namespace std;
bool comp(int a, int b){
  return a > b;
}
int main(){
  int n, k; cin >> n >> k;
  vector <int> parts;
  for(int i=0; i < n; i++){
    int x; cin >> x;
    parts.push_back(x);
  }
  sort(parts.begin(), parts.end(), comp);
    //int cont = count(parts.begin(), parts.end(), parts[n-1]);
  int cont = k;
    cont += count(parts.begin()+k, parts.end(), parts[k-1]);
  cout << cont << endl;
}
