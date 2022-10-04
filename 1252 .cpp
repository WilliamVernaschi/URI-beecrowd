#include <iostream>
#include <algorithm>

using namespace std;

int m;

bool comp(int a, int b){
  if(a%m != b%m) return a%m < b%m;
  
  else if(abs(a%2) != abs(b%2)) return abs(a%2) == 1;
  
  else if(a%2 == 0) return a < b;
  
  else return a > b;
  
  
}

int main(){
  int n;
  while(cin >> n >> m){
    cout << n << " " << m << endl;
    if(n+m == 0) break;
    int arr[n];
    for(int i = 0;i < n; i++){
      cin >> arr[i];
    }
    sort(arr, arr+n, comp);
    for(int i = 0; i < n; i++) cout << arr[i] << endl;
  }
  return 0;
}
