#include <stdio.h>
int main(){
  int t; scanf("%d", &t);
  for(int i = 0; i < t; i++){
    int n; scanf("%d", &n);
    if(n % 4 == 0)
      printf("1\n");
    else if(n%4 == 1)
      printf("7\n");
    else if(n%4 == 2)
      printf("9\n");
    else if(n%4 == 3)
      printf("3\n");
  }
    return 0;
}
