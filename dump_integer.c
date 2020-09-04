/* This program gets integer from the user and prints its value
in hex and binary modes */

#include <stdio.h>
#include "hacking.h"

void usage(char *prog_name)
{
	printf("Usage: %s <int A>\n", prog_name);
	exit(1);
}
void dump_time_struct_bytes(unsigned int *, int);

int main(int argc, char *argv[]) {
	if(argc < 2)      // If less than 2 arguments are used,
		usage(argv[0]); // display usage message and exit.

	unsigned int value = atoi(argv[1]); // convert the 2nd arg into an integer
	unsigned int *pvalue = &value;
	dump_integer_bytes(pvalue, sizeof(value));
	binary_print(value);

	return 0;
}
