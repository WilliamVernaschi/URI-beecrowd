#include <iostream>
#include <set>
 using namespace std;
 int main() {
    string s;
    set <string> joias;
    while(cin >> s){
        joias.insert(s);
    }
    cout << joias.size() << endl;
}
