#include <stdio.h>
#include "xor.h"

int main(void)
{

    printf("Hello World!\n");
    char* c1 = xor_decryptBufferByKey("hsashjdksahjkashjdashjdkashdjkashdjksadasgdhasdgshajdgshad", "123");
    char* c2 = xor_decryptBufferByKey(c1, "123");
    char* c3 = xor_decryptBufferByKey(c2, "123");
    printf("%s is c1\n", c1);
    printf("%s is c2\n", c2);
    printf("%s is c2\n", c3);

    xor_cleanup();
    return 0;
}

