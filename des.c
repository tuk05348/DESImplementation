#include <stdio.h>
#include <stdlib.h>
#include "key.h"

int main(int argc, char *argv[]){
	unsigned char key[64];
	unsigned char subkey[56];
	unsigned char cd[2][17][28];
	int seq[] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};

	key_gen(key);
	subkey_gen(subkey, key);

	print_key(key, 64);
	print_key(subkey, 56);

	for(int i=0; i<2; i++){
		copy_arr(28, i*28, subkey, cd[i][0]);
		printf("%d Half: ", i);
		print_key(cd[i][0], 28);
		for(int j=1; j<17; j++){
			left_shift(seq[j-1], 28, cd[i][j-1], cd[i][j]);
			print_key(cd[i][j], 28);
		}
	}
	return 0;
}
