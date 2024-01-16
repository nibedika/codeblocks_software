#include <stdio.h>
int main() {
  char first_letter = 'N';
  int num = 125;
  float mid_num = 25.75;
  double max_num = 123456789012345.45;

  printf("First letter: %c", first_letter);
  printf("\nInteger number: %d", num);
  printf("\nFloat number: %.2f", mid_num);
  printf("\nDouble number: %lf", max_num);
  return 0;
}
