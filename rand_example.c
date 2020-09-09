#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int i;
	printf("RAND_MAX is %u\n", RAND_MAX);
	srand(time(0));

	puts("random values from 0 to RAND_MAX");
	for(i=0; i < 8; i++)
		printf("%d\n", rand());
	puts("random values from 1 to 20");
	for(i=0; i < 8; i++)
		printf("%d\n", (rand()%20)+1);
}
