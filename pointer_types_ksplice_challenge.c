/* Different ways to do same things
https://blogs.oracle.com/linux/the-ksplice-pointer-challenge-v2 */

#include <stdio.h>

int main()
{
	int i;

	int int_array[5] = {1, 2, 3, 4, 5};

	int *int_pointer;

	int_pointer = int_array;

	for (i = 0; i < 5; i++)
	{
		printf("[integer pointer] points to %p, which contains the integer %d\n",
			   int_pointer, *int_pointer);
		int_pointer = int_pointer + 1;
	}

	for (i = 0; i < 5; i++)
	{
		printf("[integer pointer] points to %p, which contains the integer %d\n",
			   int_array + i, *(&int_array[i]));
	}

	for (i = 0; i < 5; i++)
	{
		printf("[integer pointer] points to %p, which contains the integer %d\n",
			   &int_array[i], int_array[i]);
	}

	for (i = 0; i < 5; i++)
	{
		printf("[integer pointer] points to %p, which contains the integer %d\n",
			   int_array + i, *(int_array + i)); // notation faster from gcc point of view
	}
}
