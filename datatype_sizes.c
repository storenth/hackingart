#include <stdio.h>

int main() {
	printf("The 'int' data type is\t\t\t %ld bytes\n", sizeof(int));
	printf("The 'unsigned int' data type is\t\t %ld bytes\n", sizeof(unsigned int));
	printf("The 'short int' data type is\t\t %ld bytes\n", sizeof(short int));
	printf("The 'long int' data type is\t\t %ld bytes\n", sizeof(long int));
	printf("The 'long long int' data type is\t %ld bytes\n", sizeof(long long int));
	printf("The 'off_t' data type is\t\t %ld bytes\n", sizeof(off_t));
	printf("The 'float' data type is\t\t %ld bytes\n", sizeof(float));
	printf("The 'char' data type is\t\t\t %ld bytes\n", sizeof(char));
	printf("The 'unsigned char' data type is\t %ld bytes\n", sizeof(unsigned char));

}
