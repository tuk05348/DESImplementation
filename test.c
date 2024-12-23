#include <sodium.h>
#include <stdio.h>
#include <stdlib.h>

void foo();

int main(int argc, char* argv[]){
    foo();
}

void foo() {
    char myString[32];
    uint32_t myInt;
    
    randombytes_buf(myString, 32);
    /* myString will be an array of 32 random bytes, not null-terminated */
    myInt = randombytes_uniform(10);
    /* myInt will be a random number between 0 and 9 */
    printf("%s\n%d\n", myString, myInt);
}
