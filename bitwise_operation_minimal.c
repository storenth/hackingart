#include <stdio.h>

int main() {
   int i=1, bit_a, bit_b;
   printf("bitwise OR operator  |\n");

   bit_a = (i & 2) / 2; // get the second bit (0 or 2 after &), same (i & 2) >> 1 (dividing mean 0/2 or 2/2)
   bit_b = (i & 1);     // get the first bit
   printf("%d | %d = %d\n", bit_a, bit_b, bit_a | bit_b);
   printf("\nbitwise AND operator  &\n");

   bit_a = (i & 2) / 2; // get the second bit
   bit_b = (i & 1);     // get the first bit
   printf("%d & %d = %d\n", bit_a, bit_b, bit_a & bit_b);
}
