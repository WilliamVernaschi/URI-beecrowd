#include <bits/stdc++.h>
using namespace std;
int main(){
    int v, n; cin >> v >> n;
    long double k = n * v;
    for(int i = 10; i <= 90; i += 10){
        cout << fixed << setprecision(0) << ceil((k * i) / 100);
        if(i != 90) cout << " ";
    }
    cout << "\n";
    return 0;
}
