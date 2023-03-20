#include <iostream>
 using namespace std;
 int main() {
     int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int ans=0;
        for(int i = 0; i < n; i++){
            string s; cin >> s;
            for(int j = 0; j < s.size(); j++){
                ans += i + j + s[j] - 'A';
                            }
        }
        cout << ans << '\n';
    }
     return 0;
}
