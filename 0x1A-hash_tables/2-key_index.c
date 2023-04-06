#include <string.h>

unsigned long int hash_djb2(const unsigned char *str);

unsigned long int key_index(const unsigned char *key, unsigned long int size) {
    unsigned long int hash = hash_djb2(key);
    return hash % size;
}

