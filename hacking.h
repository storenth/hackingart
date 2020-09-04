#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A function to display an error message and then exit
void fatal(char *message) {
   char error_message[100];

   strcpy(error_message, "[!!] Fatal Error ");
   strncat(error_message, message, 83);
   perror(error_message);
   exit(-1);
}

// An error checked malloc() wrapper function
void *ec_malloc(unsigned int size) {
   void *ptr;
   ptr = malloc(size);
   if(ptr == NULL)
      fatal("in ec_malloc() on memory allocation");
   return ptr;
}

// Using bit flags in combination with bitwise logic to binary convert technique.
void binary_print(unsigned int value) {
   unsigned int mask = 0xff000000; // start with a mask for the highest byte
   unsigned int shift = 256*256*256; // start with a shift for the highest byte
   unsigned int byte, byte_iterator, bit_iterator;

   for(byte_iterator=0; byte_iterator < 4; byte_iterator++) {
      byte = (value & mask) / shift; // isolate each byte
      printf(" ");
      for(bit_iterator=0; bit_iterator < 8; bit_iterator++) { // print the byte's bits
         if(byte & 0x80) // if the highest bit in the byte isn't 0
            printf("1");       // print a 1
         else
            printf("0");       // otherwise print a 0
         byte *= 2;         // move all the bits to the left by 1
      }
      mask /= 256;       // move the bits in mask right by 8
      shift /= 256;      // move the bits in shift right by 8
   }
}

// Print the bytes of the struct
void dump_integer_bytes(unsigned int *pointer, int size) {
	int i;
	unsigned char *raw_ptr; // char to be able iterate throught the time_ptr

	printf("%d bytes of integer located at 0x%08x\n",size, pointer);
	raw_ptr = (unsigned char *) pointer;
	for(i=0; i < size; i++)
	{
		printf("%02x ", raw_ptr[i]);
		if(i%16 == 15) // print a newline every 16 bytes (31%16 = 15, mean 32 bits already printed)
			printf("\n");
	}
	printf("\n");
}

// dumps raw memory in hex byte and printable split format
void dump(const unsigned char *data_buffer, const unsigned int length) {
	unsigned char byte;
	unsigned int i, j;
	for(i=0; i < length; i++) {
		byte = data_buffer[i];
		printf("%02x ", data_buffer[i]);  // display byte in hex
		if(((i%16)==15) || (i==length-1)) {
			for(j=0; j < 15-(i%16); j++)
				printf("   ");
			printf("| ");
			for(j=(i-(i%16)); j <= i; j++) {  // display printable bytes from line
				byte = data_buffer[j];
				if((byte > 31) && (byte < 127)) // outside printable char range
					printf("%c", byte);
				else
					printf(".");
			}
			printf("\n"); // end of the dump line (each line 16 bytes)
		} // end if
	} // end for
}

