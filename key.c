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
    unsigned char key[64];
    randombytes_buf(bytes, 8);
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            key[(i*8) + j] = (bytes[i] >> j) & mask;
        }
    }

    for(int i=0; i<64; i++){
        printf("%d", key[i]);
    }
    printf("\n");
}
