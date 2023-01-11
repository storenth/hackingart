#include <stdio.h>
#include <string.h>
/* get chars from stdin to char_test, then output its in revers loop */

/* vars */
char str_char;
int length_str_char, size_str_char;
int i;
char char_test[25];

/* code */
int main(){
    size_str_char = sizeof(char_test);
    
    for(i=0;i<size_str_char;i++){ // 25 times loop
        char_test[i] = getchar(); // stdin 
            if (char_test[i] == '\n') // parser for ENTER click and break loop
            {
                i--;
                break;
            }
    }
    
    length_str_char = strlen(char_test);
    //revers loop
    for(;i>=0;i--){
        putchar(char_test[i]);
    }

    printf("\nchar[] size = %d, and lens = %d\n", size_str_char, length_str_char);
    printf("ASCII equivalence of 1-st char = %d\n", char_test[0]);
    printf("\n\nexit point\n");
    return 0;
}
