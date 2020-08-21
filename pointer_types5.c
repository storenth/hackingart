#include <stdio.h>

int main() {
	int i;

	char char_array[5] = {'a', 'b', 'c', 'd', 'e'};
	int int_array[5] = {1, 2, 3, 4, 5};

	unsigned long int hacky_nonpointer;

	hacky_nonpointer = (unsigned long int) char_array; // also worked with `hacky_nonpointer = char_array`

	for(i=0; i < 5; i++) { // iterate through the char array with the hacky_nonpointer
		printf("[hacky_nonpointer] points to %p, which contains the char '%c'\n",
            hacky_nonpointer, *((char *) hacky_nonpointer));
		hacky_nonpointer = hacky_nonpointer + sizeof(char);
	}

	hacky_nonpointer = (unsigned long int) int_array;
	
	for(i=0; i < 5; i++) { // iterate through the int array with the hacky_nonpointer
		printf("[hacky_nonpointer] points to %p, which contains the integer %d\n",
            hacky_nonpointer, *((int *) hacky_nonpointer));
		hacky_nonpointer = hacky_nonpointer + sizeof(int);
	}
}
