#include <bits/stdc++.h>
using namespace std;
double vol(double l, double w, double x){
  return (l-2*x)*(w-2*x)*(x);
}
pair<double, double> solve(double l, double w){
  pair<double, double> sol;
  sol.first = ((l+w) + sqrt((l+w)*(l+w) - 3*l*w))/6;
  sol.second = ((l+w) - sqrt((l+w)*(l+w) - 3*l*w))/6;
  return sol;
}
int main(){
  double l, w;
  while(cin >> l >> w){
    pair<double, double> sol = solve(l, w);
    if(vol(l, w, sol.second) < 0)
      sol.second = min(l,w)/2;
    if(vol(l, w, sol.first) < 0)
      sol.first = min(l,w)/2;
            if(vol(l, w, sol.first) >= vol(l, w, sol.second))
      cout << fixed << setprecision(3) << sol.first << " " << 0.000 << " " << sol.second << '\n'
    else
      cout << fixed << setprecision(3) << sol.second << " " << 0.000 << " " << sol.first << '\n'
  }
    return 0;
}
