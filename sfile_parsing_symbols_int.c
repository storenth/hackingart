/* Open sequental file and read it with fgetc() to parse int numbers symbol by symbol with ctype.h to char final_string[] */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHAR 100 // maximum characters to read in char[] vars
FILE * pfile; // pointer to file location on the HDD

int main(){
    
/* vars */
    int i; // for loop counter
    int j = 0; // for final_string - isalpha counter
    char chr = '0'; // for fgetc parsing
    char buffer_string[MAX_CHAR]; // buffered characters stream from file in fgets()
    char final_string[MAX_CHAR];
    int fvar = 0; // work for count while loop, means first occurrence of the int type reached in line fvar

/* code */
    pfile = fopen("c_pro_txt/test.txt", "r"); // open file with 'w'-mode means Write, via pfile pointer object
    // if file not exist or path incorrect
    if(pfile == 0){
        puts("pointer to file fail");
        exit(1);
    }

    /* version of reading file string char by char simple and short */
    while((chr=fgetc(pfile)) != EOF){ // while - means end of the file reached + means till EOF (end of file) reached
            /* if line contain difit number */
        if(isdigit(chr)){
            final_string[j] = chr; // concatenate buffered lines to final string
            putc(final_string[j], stdout);
            j++;
        }
    }
    
    printf("\nFinal string of found numbers =\n'%s'\n and strlen(final_string) = %lu\n",final_string, strlen(final_string));
    
    fclose(pfile); // close file
    puts("File closed!");

/* exit point */
    puts("\nexit point:");
    getchar();
    return 0;
}