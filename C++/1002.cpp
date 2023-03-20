#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    const double pi = 3.14159;
    double r; cin >> r;
    cout << "A=" << setprecision(4) << fixed << pi*r*r << endl;
    return 0;
}
