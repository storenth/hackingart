/* This minimal instructions to show off the bitwise operations using bit shift */
/* https://stackoverflow.com/a/2776258/6485674 */
/* 00001010 --> 00000101 mean var /= 2^1, but 00000101 --> 00001010 multiplied by 2 to the power of k */
#include <stdio.h>

int main() {
   int i=0xff000000, bit_a, bit_b, shift = 0x1000000;
   printf("i = 0x%08x\n", i);

   printf("bitwise OR operator  |\n");

   bit_a = (i & 0xff000000)/shift; // get the second bit (0 or 2 after &), same (i & 2) >> 1 (dividing mean 0/2 or 2/2)
   bit_b = (i & 0x1);     // get the first bit
   printf("0x%08x\n", bit_a);

   printf("%d | %d = %d\n", bit_a, bit_b, bit_a | bit_b);

   printf("\nbitwise AND operator  &\n");
   printf("%d & %d = %d\n", bit_a, bit_b, bit_a & bit_b);
}
