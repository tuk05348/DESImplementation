#include <stdio.h>
#include <stdlib.h>
#include <sodium.h>

unsigned char* key_gen();
void print_key(unsigned char* key);

int main(int argc, char* argv[]){
    unsigned char* key = key_gen();
    print_key(key);
    return 0;
}

unsigned char* key_gen(){
    unsigned char bytes[8];
    unsigned char mask = 1;
    unsigned char* key = malloc(64 * sizeof(unsigned char));
    if(key == NULL){
        perror("Memory allocation failed\n");
    }
    randombytes_buf(bytes, 8);
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            key[(i*8) + j] = (bytes[i] >> j) & mask;
        }
    }

    return key;
}

void print_key(unsigned char* key){
    for(int i=0; i<64; i++){
        printf("%d", key[i]);
    }
    printf("\n");
}
