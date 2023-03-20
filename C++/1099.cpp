#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n; cin >> n;
    while(n--){
    int a, b; cin >> a >> b;
    int s = 0;
    for(int i = min(a,b) + 1; i < max(a,b); i++){
        if(i % 2 == 1) s += i;
    }
    cout << s << endl; 
    s = 0;
    }
}
