#include <iostream>

using namespace std;

long long fact(int n){
    long long result = n;
    if(n == 0) return 1;
    while(n > 1){
	n--;
	result *= (n);
    }
    return result;

}

int main(){
    int m, n;
    while(cin >> m >> n){
	cout << fixed << fact(m) + fact(n) << endl;
    }
    return 0;
}