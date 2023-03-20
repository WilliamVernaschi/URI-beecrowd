#include <iostream>
using namespace std;
int main(){
    int n, min = 21, tort = 0; cin >> n;
    for(int i = 0; i < n; i++){
        int t; cin >> t;
                if(t < min){
            tort = i+1;
            min = t;
        }   
    }   
    cout << tort << endl;
}
