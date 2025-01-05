#include <stdio.h>
#include <stdlib.h>
#include "key.h"

int main(int argc, char *argv[]){
	unsigned char key[64];
	unsigned char subkey[56];
	unsigned char cd[2][17][28];

	key_gen(key);
	subkey_gen(subkey, key);

	for(int i=0; i<2; i++){
		copy_arr(28, i*28, subkey, cd[i][0]);
	}

	print_key(key, 64);
	print_key(subkey, 56);
	print_key(cd[0][0], 28);
	print_key(cd[1][0], 28);
	return 0;
}
