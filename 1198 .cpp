#include <stdio.h>
#include <cmath>

int main(){
  long long int n1, n2;

  while(scanf("%lli %lli", &n1, &n2) != EOF){
    if(n1 > n2)  printf("%lli\n", n1-n2);
    else printf("%lli\n", n2-n1);
  }
  
  return 0;
}
