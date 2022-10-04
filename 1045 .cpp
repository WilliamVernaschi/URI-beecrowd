#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int comp(double a, double b){
  return a > b;
}

int main(){
  double tri[3]; cin >> tri[0] >> tri[1] >> tri[2];
  sort(tri, tri+3, comp);

  if(tri[0] >= tri[1] + tri[2]){
    cout << "NAO FORMA TRIANGULO" << endl;
    return 0;
  }
  else if(tri[0] * tri[0] == tri[1] * tri[1] + tri[2]*tri[2])
    cout << "TRIANGULO RETANGULO" << endl;
  else if(tri[0] * tri[0] > tri[1] * tri[1] + tri[2]*tri[2])
    cout << "TRIANGULO OBTUSANGULO" << endl;
  else if(tri[0] * tri[0] < tri[1] * tri[1] + tri[2]*tri[2])
    cout << "TRIANGULO ACUTANGULO" << endl;

  if(tri[0] == tri[1] && tri[1] == tri[2]){
    cout << "TRIANGULO EQUILATERO" << endl;
  }
  else if(tri[0] == tri[1] || tri[1] == tri[2]){
    cout << "TRIANGULO ISOSCELES" << endl;
  }



  return 0;
}
