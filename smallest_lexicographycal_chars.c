/* Test challenge for Kirill Zhdanov from Huawei:
You're given a nonempty string with length <= 1000 and consisting of lowercase English characters.
Find the lexicographically smallest subsequence of characters containing all the distinct characters exactly once. 
Example 1:
Input: "cdadabcc"
Output: "adbc" */

/* author: storenth.catena@gmail.com */
/* filename: smallest_lexicographycal_chars.c */

/* This source code solve Smallest Subsequence of Distinct Characters partially based on Bubble sort algo */
/* Optimization is required if using only allocated bytes from string provided by the user without a second array */


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/* Called when no argument provided */
void usage(char *prog_name)
{
	printf("Usage: %s <string to parse>\n", prog_name);
	exit(0);
}
/* Prototypes */
void fatal(char *);			   // a function for fatal errors
void *ec_malloc(unsigned int); // an errorchecked malloc() wrapper

/* Entry point */
int main(int argc, char *argv[])
{
	char *buffer, *output; // user input and resolved output
	int did_swap; // check lexicographical order
	int swapped; // already checked char marker
	int index = 0; // output iterator

	buffer = (char *)ec_malloc(1000); // based on a given case: string with length <= 1000

	if (argc < 2)		// If there aren't commandline arguments
		usage(argv[0]); // display usage message and exit

	strcpy(buffer, argv[1]); // copy user input
	output = (char *)ec_malloc(strlen(buffer)+1); // second array for final stdout, bytes allocated for worse case

	for (int i = 0; i < strlen(buffer); ++i)
	{
		did_swap = 0;
		swapped =0;
		for (int j = i + 1; j < strlen(buffer); ++j)
		{
			if (buffer[i] > buffer[j]){
				did_swap = 1;
			}
			else if (buffer[i] == buffer[j]) { // entries equal
				if (did_swap && !swapped){
					buffer[i] = '_';
				}
				else{
					swapped = 1;
					buffer[j] = '_'; // mock similar chars, optimization required in case of bits shift approach
				}
			}
		}
		if (buffer[i] != '_') {
			output[index] = buffer[i];
			index++;
		}
	}

	printf("Finally stdout: %s\n", output);

	// memory free
	free(buffer);
	free(output);
}

// A function to display an error message and then exit
void fatal(char *message)
{
	char error_message[100];

	strcpy(error_message, "[!!] Fatal Error ");
	strncat(error_message, message, 83);
	perror(error_message);
	exit(-1);
}

// An error checked malloc() wrapper function
void *ec_malloc(unsigned int size)
{
	void *ptr;
	ptr = malloc(size);
	if (ptr == NULL)
		fatal("in ec_malloc() on memory allocation");
	return ptr;
}
