#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

typedef long double ll;

const long long INF = 1000000000;
const long double EPS=0.000001;

struct point{
  long double x, y;
};

ll dist(point p1, point p2){
  return (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
}





int main(){
  int n;
  while(cin >> n){
    if(!n) break;
    vector <point> points;
    for(int i = 0; i < n; i++){
      point p; cin >> p.x >> p.y;
      points.push_back(p);
    }
    //cout << n << " " << dist(points[0], points[1]) << endl;
    ll closest=INF;
    for(int i = 0; i < n; i++){
      for(int j = i+1; j < n; j++){
        ll curr_dist = dist(points[i], points[j]);
        //cout << curr_dist << endl;
        if(curr_dist < closest) closest = curr_dist;
      }
    }
    if((sqrtl(closest) - 10000 > EPS)){
      cout << "INFINITY" << endl;
    }
    else{
      cout << setprecision(4) << fixed << sqrtl(closest) << endl;
    }
  }
}
