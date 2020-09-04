/* The input will contain two integers, a and b, separated by a space. */
/* The program print the absolute difference value of A and B */
/* https://www.hackerrank.com/challenges/pointer-in-c/problem */

#include <stdio.h>
#include <stdlib.h>

void usage(char *prog_name)
{
	printf("Usage: %s <int A> <int B>\n", prog_name);
	exit(0);
}

int absolute_difference(int *a, int *b);

int main(int argc, char *argv[]){
	int A, B;
	int *pa = &A, *pb = &B;

	if (argc < 3)		 // If there aren't commandline arguments
		usage(argv[0]); // display usage message and exit

	A = atoi(argv[1]);
	B = atoi(argv[2]);

	printf("[DEBUG] A @ %p: \'%d\'\n", &A, A);
	printf("[DEBUG] B @ %p: \'%d\'\n", &B, B);

	printf("[Absolute difference] A - B \'%d\'\n", absolute_difference(pa, pb));

	printf("[DEBUG] pa -> %p: \'%d\'\n", pa, *pa);
	printf("[DEBUG] pb -> %p: \'%d\'\n", pb, *pb);
}

int absolute_difference(int *a, int *b)
{
	int c = *a - *b;
	return c > 0 ? c : (-1)*c;
}
