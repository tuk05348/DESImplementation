#include <stdio.h>
#include <stdlib.h>
#include <sodium.h>

void key_gen(unsigned char* key){
    unsigned char bytes[8];
    unsigned char mask = 1;
    randombytes_buf(bytes, 8);
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            key[(i*8) + j] = (bytes[i] >> j) & mask;
        }
    }
}

void print_key(unsigned char* key, int key_len){
    for(int i=0; i<key_len; i++){
        printf("%d", key[i]);
    }
    printf("\n");
}

void subkey_gen(unsigned char* subkey, unsigned char* key){
    int PC1[56] = {57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18, 10, 2, 59, 51, 43, 35, 27, 19, 11, 3, 60, 52, 44, 36, 63, 55, 47, 39, 31, 23, 15, 7, 62, 54, 46, 38, 30, 22, 14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28, 20, 12, 4};

    for(int i=0; i<56; i++){
        subkey[i] = key[PC1[i]];
    }

}

void left_shift(int n, int len, unsigned char* orig, unsigned char* res){
    if(n > len){
        n %= len;
    }

    for(int i=0; i<len-n; i++){
		res[i] = orig[i+n];
	}
	for(int i=0; i<n; i++){
		res[len-n+i] = orig[i];
	}
}
