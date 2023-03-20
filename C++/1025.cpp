#include <bits/stdc++.h>
using namespace std;
int marbles[10001];
int bin_search(int x, int n){
  int begin = 0, end = n, mid;
  while(begin <= end){
    //cout << begin << " " << end << endl;
    mid = (begin+end)/2;
    if(marbles[mid] == x && (mid == 0 || marbles[mid-1] < x)){
      return mid;
    }
    else if(marbles[mid] < x){
      begin = mid + 1;
    }
    else{
      end = mid - 1;
    }
  }
  return -1;
}
int main(){
  int n, q, case_n=0;
  while(cin >> n >> q){
    if(n+q == 0) break;
    case_n++;
    cout << "CASE# " << case_n << ":" << endl;
    memset(marbles, 0, 10001*sizeof(int));
    for(int i = 0; i < n; i++){
      cin >> marbles[i];
    }
    sort(marbles, marbles+n);
    for(int i = 0; i < q; i++){
      int x; cin >> x;
      int idx = bin_search(x, n);
      if(idx != -1)
        cout << x << " found at " << idx+1 << endl;
      else
        cout << x << " not found" << endl;
    }
  }
  return 0;
}
