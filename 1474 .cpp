#include <iostream>

using namespace std;

typedef long long ll;

#define MOD 1000000

void multmat(ll a[2][2], ll b[2][2], ll res[2][2]){

  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 2; j++){
      res[i][j] = ((a[i][0] % MOD * b[0][j] % MOD) % MOD);
      res[i][j]+= ((a[i][1] %MOD * b[1][j] % MOD) % MOD);
      res[i][j] %= MOD;
    }
  }
  
}

void expbin(ll a[2][2], ll n, ll b[2][2]){
  ll aux[2][2];
  if(n == 0){
    b[0][0] = 1;
    b[1][1] = 1;
    b[1][0] = 0;
    b[0][1] = 0;
  }
  else if(n % 2){
    expbin(a, n-1, aux);
    multmat(a, aux, b);
  }
  else{
    expbin(a, n/2, aux);
    multmat(aux, aux, b);
  }
}

int main(){
  ll n=0, l=0, k=0; 
  while(scanf("%lli %lli %lli", &n, &l, &k) != EOF){
    n /= 5;

    //cout << n << endl << l << endl << k << endl;

    ll base[2][2] = {{l, k}, {1, 0}};

    ll mat_tl_linear[2][2] = {{0, 0}, {0, 0}};

    //ll m1[2][2] = {{2, 5}, {23, 54}};
    //ll m2[2][2] = {{9, 21}, {17, -1}};
    //expbin(m1, 3, aux);
    expbin(base, n-1, mat_tl_linear);
    //cout << mat_tl_linear[0][0] << " " <<  mat_tl_linear[0][1] << endl;
    //cout << mat_tl_linear[1][0] << " " << mat_tl_linear[1][1] << endl;

    printf("%06lld\n", (mat_tl_linear[0][0]*(l % MOD) + mat_tl_linear[0][1]*1) %MOD) ;
    
  }
  return 0;
}
