#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        unsigned long long int num_graos = 0, casa; cin >> casa;
        num_graos = pow(2, casa-5);
        cout << fixed << num_graos / 375 << " kg" << endl;
    }
}