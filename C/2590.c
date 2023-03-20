#include <stdio.h>
int main() {
  // SOLVED BY CHAT GPT
  
  // Create a lookup table for the last digits of the powers of 7
  int lastDigits[4] = {1, 7, 9, 3};
  // Read the number of test cases
  int t;
  scanf("%d", &t);
  // Iterate over the test cases
  for (int i = 0; i < t; i++) {
    // Read the value of n
    int n;
    scanf("%d", &n);
    // Calculate the last digit of the nth power of 7 using the lookup table
    int lastDigit = lastDigits[n % 4];
    // Print the result
    printf("%d\n", lastDigit);
  }
  return 0;
}
