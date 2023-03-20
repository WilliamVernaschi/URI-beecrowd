#include <bits/stdc++.h>
using namespace std;
string shift_string(string s, int n, int begin, bool step){
    string r = "";
    for(int i = 0; i < s.length(); i++){
    if(i < begin || (!(s[i] <= 90 && s[i] >= 65) && !(s[i] <= 122 && s[i] >= 97)) && step){
        r += s[i];
    }
    else{
        r += s[i] + n;
            }
    //cout << s[i] << " -> " << r[i] << endl;
    }
    return r;
}
int main(){
    int n; cin >> n;
    cin.ignore();
    string s = "";
    //char c = 122;
    //cout << c << endl;
    while(n--){
    getline(cin, s);
    //cout << s[1] <= 90 << endl;
    s = shift_string(s, 3, 0, true);
    reverse(s.begin(), s.end());
    s = shift_string(s, -1, s.length() / 2, false);
    cout << s << endl;
    s = "";
    }
    return 0;
}
