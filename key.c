//Niaz Baharudeen
//26 January 2025
//DES Implementation
//Key Functions
//Family of functions designed to support generation of keys and subkeys for the DES Algorithm

#include <stdio.h>
#include <stdlib.h>
#include <sodium.h>

//Generates a random 64 bit key using the Libsodium Library
//Takes in a pointer to an unsigned char key that should have 64 bits of space allocated
void key_gen(unsigned char* key){
    unsigned char bytes[8]; //unsigned char of 8 bytes = 64 bits
    unsigned char mask = 1; //bit mask
    randombytes_buf(bytes, 8); //use lsodium function to generate 8 random bytes
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){ //convert each byte into bits and store them in key pointer
            key[(i*8) + j] = (bytes[i] >> j) & mask;
        }
    }
}

//Prints a key to screen character by character
//Takes in a pointer to the key and an int of the length of the key
void print_key(unsigned char* key, int key_len){
    for(int i=0; i<key_len; i++){ //Iterate across the key and print it
        printf("%d", key[i]);
    }
    printf("\n"); //print newline character
}

//Generates a 56 bit subkey from a 64 bit key using the PC-1 table to shuffle the bits of the key to new positions
//8 bits total are dropped from the 56 bit key
//Takes in both a pointer to the uninitialized subkey and a pointer to the key
void subkey_gen(unsigned char* subkey, unsigned char* key){
    int PC1[56] = {57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18, 10, 2, 59, 51, 43, 35, 27, 19, 11, 3, 60, 52, 44, 36, 63, 55, 47, 39, 31, 23, 15, 7, 62, 54, 46, 38, 30, 22, 14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28, 20, 12, 4};

    for(int i=0; i<56; i++){ //Subkey initialized by rearranging bits in 64 bit key, 8 bits dropped to get 56 bits
        subkey[i] = key[PC1[i]];
    }

}

//Left shift function to rotate a key by a designated number, the leftmost bits are transposed to the end of the key
//Takes in the number of shifts, length of key, and pointers to the key being shifted and the new key to initialize with the shift
void left_shift(int n, int len, unsigned char* orig, unsigned char* res){
    if(n > len){ //if shift greater than length, reduce it with modulo to get equivalent shift
        n %= len;
    }

    for(int i=0; i<len-n; i++){ //take the rightmost bits and shift them up by the number of shifts
		res[i] = orig[i+n]; //populate new key with shift
	}
	for(int i=0; i<n; i++){ //take the leftmost bits and populate them at the end of the new key
		res[len-n+i] = orig[i];
	}
}

//Copy array function that copies one array to another starting at a specific index with a specific number of elements to copy
//Takes in length of copy, starting index, pointer to source array, and pointer to destination array
void copy_arr(int n, int d, unsigned char* src, unsigned char* dest){
	for(int i=d; i<n+d; i++){ //start at index, and copy n number of elements from source
		dest[i-d] = src[i]; //offset index in destination array
	}
}
