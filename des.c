#include <stdio.h>
#include <stdlib.>
#include "key.h"

int main(int argc, char *argv[]){
    unsigned char key[64];
    key_gen(key);
    unsigned char subkey[56];
    subkey_gen(subkey, key);
    print_key(key, 64);
    print_key(subkey, 56);
    unsigned char  subkey_1[56];
    left_shift(1, 56, subkey, subkey_1);
    print_key(subkey_1);
    return 0;
}
