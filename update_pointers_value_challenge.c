/* The input will contain two integers, a and b, separated by a space. */
/* void absolute_difference(int *A,int *B), which reads two integers as argument, and sets `a` with the sum of them,
and `b` with the absolute difference of them. */
/* https://www.hackerrank.com/challenges/pointer-in-c/problem */

#include <stdio.h>
#include <stdlib.h>

void usage(char *prog_name)
{
	printf("Usage: %s <int A> <int B>\n", prog_name);
	exit(0);
}

void update(int *a, int *b);

int main(int argc, char *argv[]){
	int A, B;
	int *pa = &A, *pb = &B;

	if (argc < 3)		 // If there aren't commandline arguments
		usage(argv[0]); // display usage message and exit

	A = atoi(argv[1]);
	B = atoi(argv[2]);

	printf("[DEBUG] A @ %p: \'%d\'\n", &A, A);
	printf("[DEBUG] B @ %p: \'%d\'\n", &B, B);
	update(pa, pb);

	printf("[Absolute difference] A - B \'%d\'\n", *pb);

	printf("[DEBUG] pa -> %p: \'%d\'\n", pa, *pa);
	printf("[DEBUG] pb -> %p: \'%d\'\n", pb, *pb);
}

void update(int *a, int *b)
{
	int c = *a + *b;
	int d = *a - *b;
	if (d > 0){
		*b = d;
	}
	else *b = (-1)*d;
	*a = c;
}
