#include <iostream>
using namespace std;
int main() {
  // Read the age in days
  int ageInDays;
  cin >> ageInDays;
  // Calculate the number of years, months, and days
  int years = ageInDays / 365;
  int months = (ageInDays % 365) / 30;
  int days = (ageInDays % 365) % 30;
  // Print the result
  cout << years << " ano(s)" << endl;
  cout << months << " mes(es)" << endl;
  cout << days << " dia(s)" << endl;
  return 0;
}
