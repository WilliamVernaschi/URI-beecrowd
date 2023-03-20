#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
typedef long double ld;
const ld PI = M_PI;
ld r(ld a, ld b, ld c){
  ld p = (a+b+c)/(2.0);
  ld vz = sqrt((p)*(p-a)*(p-b)*(p-c));
  ld rz = ((2.0)*vz)/(a+b+c);
  return PI*rz*rz;
}
ld v(ld a, ld b, ld c){
  ld p = (a+b+c)/(2.0);
  return sqrt((p)*(p-a)*(p-b)*(p-c))-r(a,b,c);
}
ld s(ld a, ld b, ld c){
  ld p = (a+b+c)/(2.0);
  ld vz = sqrt((p)*(p-a)*(p-b)*(p-c));
  ld alph = acos((-b*b - a*a + c*c)/(-2*b*a));
  ld rz = c/(sqrt(2*(1-cos(2*alph))));
  return PI*rz*rz - vz;
}
int main(){
  ld a, b, c; 
  while(cin >> a >> b >> c){
    cout << fixed << setprecision(4) << s(a,b,c) << " " << v(a,b,c) << " " << r(a,b,c) << endl
  }
  }
