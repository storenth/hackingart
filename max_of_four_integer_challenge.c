/* Program reads four arguments and returns the greatest of them. */
/* https://www.hackerrank.com/challenges/functions-in-c/problem */

#include <stdio.h>
#include <stdlib.h>

void usage(char *prog_name)
{
	printf("Usage: %s <int A> <int B>\n", prog_name);
	exit(0);
}

/* Prototype */
int max_of_four(int a, int b, int c, int d);

int main(int argc, char *argv[])
{
	int a, b, c, d;
	if (argc < 4)		// If there aren't commandline arguments
		usage(argv[0]); // display usage message and exit

	a = atoi(argv[1]);
	b = atoi(argv[2]);
	c = atoi(argv[3]);
	d = atoi(argv[4]);

	int ans = max_of_four(a, b, c, d);
	printf("%d", ans);

	return 0;
}

// Get four integer and return greatest
int max_of_four(int a, int b, int c, int d)
{
	int arr[] = {a,b,c,d};
	int max, sum = a + b + c + d;
	float temp, min = 999999999;
	for (int i = 0; i < 4; i++)
	{
		temp = sum/arr[i];
		if(temp < min){
			min = temp;
			max = arr[i];
		}
	}
	return max;
}
