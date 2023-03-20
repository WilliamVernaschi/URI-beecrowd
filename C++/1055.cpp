#include <iostream>
#include <deque>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
  int t; cin >> t;
  for(int k=1; k <= t; k++){
    int n; cin >> n;
    vector <int> nums; nums.resize(n);
    for(int i = 0; i < n; i++){
      cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    deque <int> newnum;
    int sum = 0;
    for(int i = 0; i < n/2; i++){
      if(i%2 == 0){
        newnum.push_front(nums[i]);
        newnum.push_back(nums[n-i-1]);
      }
      else{
        newnum.push_front(nums[n-i-1]);
        newnum.push_back(nums[i]);
      }
    }
    for(int i = 0; i < newnum.size() - 1; i++){
      sum += abs(newnum[i] - newnum[i+1]);
    }
    if(n % 2 == 1)
      sum += max(abs(newnum[0] - nums[n/2]), abs(newnum[n-2] - nums[n/2]));
        cout << "Case " << k << ": " << sum << endl;
  }
  return 0;
}
