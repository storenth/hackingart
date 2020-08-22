
/* This program print 0
bacause all 32-bits (all binary 1s: 0x11111111 = 4294967295) + 0x1 (4294967295 + 1 = 4294967296)
cause overflow of the 4 byte segment, so we got  0x00000000 (0x11111111 + 0x00000001)*/
#include <stdio.h>

int main()
{
    /* boundary value analysis */
    unsigned int i = 4294967296;
    printf("%ld\n", sizeof(i));
    printf("%d\n", i);

    return 0;
}
