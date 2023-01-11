/* Open sequential file and read it with fgets() to parse int numbers with ctype.h to char final_string[] */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHAR 100 // maximum characters to read in char[] vars
FILE * pfile; // pointer to file location on the HDD

int main(){
    
/* vars */
    char esc = 'X'; // exit point
    int i; // for loop counter
    int j = 0; // for final_string - isalpha counter
    char buffer_string[MAX_CHAR]; // buffered characters stream from file in fgets()
    char final_string[MAX_CHAR];
    int fvar = 0; // work for count while loop, means first occurrence of the int type reached in line fvar

/* code */
    // prototype full path = "/Volumes/My Book Thunderbolt Duo/documents/stroustrup/c_pro/c_pro_txt/test.txt"
    // pfile = fopen("/User/imacuser/Documents/test.txt", "r"); // open file via pfile pointer object

    pfile = fopen("c_pro_txt/test.txt", "r"); // open file with 'w'-mode means Write, via pfile pointer object
    // if file not exist or path incorrect
    if(pfile == 0){
        puts("pointer to file fail");
        exit(1);
    }

    /* while method - try to find number line of the .txt-file */

    /* 1-st version very stable but too long */
    // while(!feof(pfile)){ // while 0 - means last of the file lines reached
    //     fvar++;
    //     printf("while loop count %d\n", fvar);
    //     if(fgets(buffer_string, MAX_CHAR, pfile) != '\0'){ // means till EOF (end of file) reached
    //         for(i = 0; i< strlen(buffer_string); i++){
    //             /* if line contain difit number */
    //             if(isdigit(buffer_string[i])){
    //                 final_string[j] = buffer_string[i]; // concatenate buffered lines to final string
    //                 j++;
    //             }
    //         }
    //    }
    //    else final_string[j] = '\0';
    // }
    
    /* 2-nd version of reading file string simple and short */
    while(fgets(buffer_string, MAX_CHAR, pfile) != '\0'){ // while '\0' - means last of the file lines reached + means till EOF (end of file) 
                                                            // reached, because fgets return NULL when EOF
        for(i = 0; i< strlen(buffer_string); i++){
            /* if line contain difit number */
            if(isdigit(buffer_string[i])){
                final_string[j] = buffer_string[i]; // concatenate buffered lines to final string
                putc(final_string[j], stdout);
                j++;
            }
        }
    } 
    
    printf("Final string of found numbers = \n'%s'\n and strlen(final_string) = %d\n",final_string, strlen(final_string));
    
    fclose(pfile); // close file
    puts("File closed!");

/* exit point */
    puts("\nexit point:");
    scanf(" %c", &esc);
    return 0;
}