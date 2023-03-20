#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int a, b; cin >> a >> b;    
    int s = 0;    
     for(int i = min(a,b) ; i <= max(a,b); i++){
        if(i % 13 != 0) s += i;
    }
        cout << s << endl;
}
