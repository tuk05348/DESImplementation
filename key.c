#include <stdio.h>
#include <stdlib.h>
#include <sodium.h>

unsigned char* key_gen();
void print_key(unsigned char* key, int key_len);
unsigned char* subkey_gen();

int main(int argc, char* argv[]){
    unsigned char* key = key_gen();
    print_key(key, 64);
    unsigned char* subkey = subkey_gen(key);
    print_key(subkey, 56);
    free(key);
    free(subkey);
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

void print_key(unsigned char* key, int key_len){
    for(int i=0; i<key_len; i++){
        printf("%d", key[i]);
    }
    printf("\n");
}

unsigned char* subkey_gen(unsigned char* key){
    int PC1[56] = {57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18, 10, 2, 59, 51, 43, 35, 27, 19, 11, 3, 60, 52, 44, 36, 63, 55, 47, 39, 31, 23, 15, 7, 62, 54, 46, 38, 30, 22, 14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28, 20, 12, 4};
    unsigned char *subkey = malloc(56 * sizeof(unsigned char));
    if(subkey == NULL){
        perror("Memory allocation failed\n");
    }
    for(int i=0; i<56; i++){
        subkey[i] = key[PC1[i]];
    }
    return subkey;
}
