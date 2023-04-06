#include <stdlib.h>
#include <string.h>

typedef struct hash_node_s {
    char *key;
    char *value;
    struct hash_node_s *next;
} hash_node_t;

typedef struct hash_table_s {
    unsigned long int size;
    hash_node_t **array;
} hash_table_t;

hash_table_t *hash_table_create(unsigned long int size);
unsigned long int key_index(const unsigned char *key, unsigned long int size);
unsigned long int hash_djb2(const unsigned char *str);

int hash_table_set(hash_table_t *ht, const char *key, const char *value) {
    unsigned long int index;
    hash_node_t *new_node, *cur_node;

    if (key == NULL || *key == '\0') {
        return 0;  // invalid key
    }

    index = key_index((const unsigned char *)key, ht->size);
    cur_node = ht->array[index];

    // check if key already exists in hash table
    while (cur_node != NULL) {
        if (strcmp(cur_node->key, key) == 0) {
            free(cur_node->value);  // free old value
            cur_node->value = strdup(value);  // set new value
            return 1;  // success
        }
        cur_node = cur_node->next;
    }

    // key not found, so create a new node and add to front of list
    new_node = malloc(sizeof(hash_node_t));
    if (new_node == NULL) {
        return 0;  // allocation error
    }
    new_node->key = strdup(key);
    new_node->value = strdup(value);
    new_node->next = ht->array[index];
    ht->array[index] = new_node;

    return 1;  // success
}

