//Niaz Baharudeen
//26 January 2025
//DES Implementation
//Implementation of the main DES algorithm using the functions from the key family of functions

#include <stdio.h>
#include <stdlib.h>
#include "key.h"

int main(int argc, char *argv[]){
	//Initialization of needed variables
	unsigned char key[64]; //64 bit key
	unsigned char subkey[56]; //56 bit subkey
	unsigned char cd[2][17][28]; //16 sets of the 2 halves of the subkey put through the left shift sequence
	int seq[] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1}; //left shift sequence

	key_gen(key); //create 64 bit key
	subkey_gen(subkey, key); //create 56 bit subkey

	print_key(key, 64); //print both keys to screen
	print_key(subkey, 56);

	for(int i=0; i<2; i++){ //for each pair of subkey halves, copy the previous pair and left-shift it per the sequence
		copy_arr(28, i*28, subkey, cd[i][0]); //copy the first subkey half
		printf("%d Half: ", i); //print to screen
		print_key(cd[i][0], 28);
		for(int j=1; j<17; j++){ //shift the subkey 16 times per the sequence, using each shifted key to generate the next
			left_shift(seq[j-1], 28, cd[i][j-1], cd[i][j]); //left shift number of times per the sequence
			print_key(cd[i][j], 28);
		}
	}
	return 0;
}
