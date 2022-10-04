#include <iostream>
#include <set>
#include <map>

using namespace std;

auto comp = [](pair<int, char> a, pair<int, char> b){
  if(a.first != b.first){
    return a.first < b.first;
  }
  else{
    return a.second > b.second;
  }
};

int main(){
  string s, next; cin >> s;
  do{
    map <char, int> frequencies;
    for(char c: s){
      frequencies[c]+=1;
    }
    set <pair<int, char>, decltype(comp)> frequencies_ordered(comp);

    for(auto el : frequencies){
      frequencies_ordered.insert(make_pair(el.second, el.first));
    }
    for(auto el : frequencies_ordered){
      cout << (int)el.second << " " << el.first << '\n';
    }
    if(cin >> next)
      cout << '\n';
    else{
      return 0;
    }
    s = next;
  }
  while(true);
  return 0;
}
