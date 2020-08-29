/* Test challenge for Kirill Zhdanov from Huawei */
/* storenth.catena@gmail.com */
/* This source code solve Smallest Subsequence of Distinct Characters partially based on Bubble sort algo */


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
	char esc;
	char *user_entry;
	char buffer = 0;
	int did_swap = 0;

	user_entry = (char *)ec_malloc(100);

	if (argc < 2)		// If there aren't commandline arguments
		usage(argv[0]); // display usage message and exit

	strcpy(user_entry, argv[1]); // copy user input

	for (int i = 0; i < strlen(user_entry); ++i)
	{
		for (int j = i + 1; j < strlen(user_entry); ++j)
		{
			if (user_entry[i] > user_entry[j] && user_entry[i] != user_entry[j]) // compare current and next values of the string
			{
				buffer = user_entry[i];
				user_entry[i] = user_entry[j];
				user_entry[j] = buffer;
			}
			if (user_entry[i] == user_entry[j]) { // entries equal
				buffer = user_entry[strlen(user_entry)-1];
				if (buffer != user_entry[j]){ // try to swap with latest entry
					user_entry[j] = buffer;
					user_entry[strlen(user_entry)-1] = '\0'; // terminate string and reduce it length
				}
				else{
					user_entry[i] = '_'; // mock similar chars, optimization required!
				}
			}
		}
	}

	printf("Finally: %s\n", user_entry);

	free(user_entry);
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
