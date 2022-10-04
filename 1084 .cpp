#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main(){
  int n, d;
  while(cin >> n >> d){
    if(n+d == 0) return 0;
    string num; cin >> num;
    stack <char> s;
    s.push(num[0]);

    for(int i = 1; i < n; i++){
      if(n-i == d && num[i] <= s.top()){ // must remove all of the remaining
        d--;
        continue; 
      }

      while(!s.empty() && s.top() < num[i] && d>0){
        s.pop();
        d--;
      }
      s.push(num[i]);
    }

    string answer;
    do{
      answer += s.top();
      s.pop();
    }
    while(!s.empty());
    reverse(answer.begin(), answer.end());
    cout << answer << endl;

  }
  return 0;
}