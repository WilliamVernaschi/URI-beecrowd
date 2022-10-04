#include <iostream>
#include <cstring>

using namespace std;


int main(){
  int n;

  int balls[1001][1001], best_sum[1001][1001];

  const int INF = 100000007;

  while(cin >> n){
    if(!n) break;

    memset(balls, 0, 1001*1001*sizeof(int));
    memset(best_sum, 0, 1001*1001*sizeof(int));

    for(int j = n; j >= 0; j--){
      for(int i = 0; i < n-j; i++){
        cin >> balls[i][j];
      }
    }



    for(int i = 0; i < n; i++){
      for(int j = n-i-2; j >= 0; j--){
        balls[i][j] += balls[i][j+1];
      }
    }

    
    int biggest_sum = 0;

    for(int i = 0; i < n; i++){
      for(int j = 0; j < n-i; j++){
        if(i == 0){
          best_sum[i][j] = balls[i][j];
        }
        else{
          int best = -INF;
          //cout << "analisando " << i << " " << j << endl;
          for(int k = 0; k < j+2; k++){
            best = max(best, best_sum[i-1][k]);
            //cout << "analisando " << i-1 << " " << k << " " << best_sum[i-1][k] << endl;
          }
          
          best_sum[i][j] = balls[i][j] + best;
        }
        biggest_sum = max(best_sum[i][j], biggest_sum);
        //cout << i << " " << j << " " << best_sum[i][j] << endl;
      }
    }

    cout << biggest_sum << endl;
    
  }
}
