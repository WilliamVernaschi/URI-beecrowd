#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    long double m, n;
    int k, x = 0, y = 0;
    cin >> n >> m >> k;
    long double temp_n = n, temp_m = m;
    while((x+1)*(y+1) < k){
        if(temp_n > temp_m){
            x++; temp_n *= x; temp_n /= (x+1);
            if((y+1)*(x+1) > k){
                x--;
                break;
            }
        }
        else{
            y++; temp_m *= y; temp_m /= (y+1);
            if((y+1)*(x+1) > k){
                y--;
                break;
            }
        }
    }
    n /= (x+1);
    m /= (y+1);
    cout << setprecision(0) << fixed << max(ceil(n), ceil(m)) << endl;
    return 0;
}
