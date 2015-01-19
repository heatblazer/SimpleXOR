#include "xor.h"
#include <stdlib.h>
/* program specific tools */

/* this will put refs to all calls from
 * the xor copy of the buffer
 * the size is fixed and will fall if exceeded
 * TODO is to implement it as a linked list
 *
*/

#define HEAP_SIZE 12512000
#define PRESERVE_HEADER /* this will preserve the file headr, like BMP, MPE, ELF, etc. */

char* safeDelete[HEAP_SIZE];
unsigned int heapIterator = 0;


int xor_auxStrlen(const char* data);
int xor_auxStrlen(const char* data) {
    size_t i=0;
    while ( data[i++] != '\0');
    return i-1;
}

size_t privateBuffLength;
size_t privateKeyLength;
/********************************************************************************************/

char* xor_decryptBufferByKey(const char *buffer, const char *key) {
    privateBuffLength = privateBuffLength == 0 ? xor_auxStrlen(buffer) : privateBuffLength;
    privateKeyLength = privateKeyLength == 0 ? xor_auxStrlen(key) : privateKeyLength;
    printf("#1: length is :%d key is %d\n", privateBuffLength, privateKeyLength);
    char* tempBuffer = (char*)malloc(sizeof(buffer) * privateBuffLength);
    char* start = tempBuffer;
    safeDelete[heapIterator++] = tempBuffer;

    int i=0;
    char c;
    while ( i < privateBuffLength ) {
#ifdef PRESERVE_HEADER
        if (i==0 || i==1 || i==2) c = buffer[i];
#endif
        c = buffer[i] ^ key[i%privateKeyLength];
        /* this check is important, since XOR can turn a charcter into '0'
         * terminator and end the string */
        if ( c == '\0') c =  buffer[i] ^ key[i%privateKeyLength];
        tempBuffer[i] = c;
        i++;
    }
    return start;
}

/* programme is responsible to call the cleanup()
    the final user however is not.
*/
int xor_cleanup() {
    unsigned int i=0;
    while (i < heapIterator) free(safeDelete[i++]);
}
