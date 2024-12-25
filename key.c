#include <stdio.h>
#include <stdlib.h>
#include <sodium.h>

void key_gen();

int main(int argc, char* argv[]){
    key_gen();
    return 0;
}

void key_gen(){
    unsigned char bytes[8];
    unsigned char mask = 1;
    unsigned char key[8];
    randombytes_buf(bytes, 8);

    for (int i=0; i<8; i++){
        key[i] = (bytes[0] >> i) & mask;
    }
    for (int i = 0; i < 8; i++) {
        printf("%d", key[i]);
    }
    printf("\n");
}
