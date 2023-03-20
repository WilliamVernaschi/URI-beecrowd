#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
bool primos_bool[50000];
vector <int> primos;
void crivo(){
  for(int i = 2; i < 50000; i++){
    if(primos_bool[i]) continue;
    else{
      primos.push_back(i);
    }
    for(int j=i+i; j < 50000; j+=i){
      primos_bool[j]=true;
    }
  }
}
int main(){
    int n;
  while(cin >> n){
    if(!n) break;
    primos.push_back(0);
    crivo();
    vector <int> p;
    for(int i = 0; i < n; i++)
      p.push_back(i+1);
    int curr_prime=1, curr_pos=0, last=-1; 
    while(p.size() > 0){
      curr_pos = (curr_pos + primos[curr_prime]-1)%p.size();
            last = p[curr_pos];
      p.erase(p.begin() + curr_pos);
            curr_prime++;
    }
    cout << last << endl;
          }
  return 0;
}
