#ifndef key_h
#define key_h

void key_gen(unsigned char* key);
void print_key(unsigned char* key, int key_len);
void subkey_gen(unsigned char* subkey, unsigned char* key);
void left_shift(int n, int len, unsigned char* orig, unsigned char* res);
void copy_arr(int n, int d, unsigned char* src, unsigned char* dest);

#endif
