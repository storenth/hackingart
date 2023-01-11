#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

/*
	simple bubble sort algo
*/
main()
{
	#define  RAND_LEN 5
	/* vars */
	char esc;
	int rand_number[RAND_LEN] = {0};
	time_t timer;
	int temp_i, temp_j, buffer, did_swap = 0;

	/* code */

	puts("random number befor buble_sort");
    // random numbers Always will be different on execution because "seed"
	srand(time(&timer));
	// [1-rand_len]  rand numbers
	for (int i = 0; i < RAND_LEN; ++i)
	{
		rand_number[i] = (rand()%10)+1;
		printf("%d\n", rand_number[i]);
	}

	//sort
	//to compare i value with other - do i <= j?
	for (int i = 0; i < RAND_LEN; ++i)
	{
		printf("%s\n", "outer counter");
		for (int j = i+1; j < RAND_LEN; ++j)
		{
			if (rand_number[i] > rand_number[j])
			{
				buffer = rand_number[i];
				rand_number[i] = rand_number[j];
				rand_number[j] = buffer;
				did_swap = 1;
				//partial sorted sdtout
				printf("%s\n", "partial sorted sdtout");
				for (int i = 0; i < RAND_LEN; ++i)
				{
					printf("%d\n", rand_number[i]);
				}

			}
		}
	}

	//sorted stdo
	putchar('\n');
	for (int i = 0; i < RAND_LEN; ++i)
	{
		printf("%d\n", rand_number[i]);
	}

    //exit poit
    printf("\n\nexit point\n");
	scanf(" %c", &esc);
	return 0;
}