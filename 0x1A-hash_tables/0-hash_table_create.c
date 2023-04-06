#include <stdlib.h>

typedef struct hash_node {
    char *key;
    void *value;
    struct hash_node *next;
} hash_node_t;

typedef struct hash_table {
    unsigned long int size;
    hash_node_t **array;
} hash_table_t;

hash_table_t *hash_table_create(unsigned long int size) {
    // Allocate memory for hash table
    hash_table_t *table = malloc(sizeof(hash_table_t));
    if (table == NULL) {
        return NULL;
    }

    // Allocate memory for array of pointers to hash nodes
    hash_node_t **array = malloc(size * sizeof(hash_node_t *));
    if (array == NULL) {
        free(table);
        return NULL;
    }

    // Initialize each pointer to null
    for (unsigned long int i = 0; i < size; i++) {
        array[i] = NULL;
    }

    // Set properties of hash table
    table->size = size;
    table->array = array;

    return table;
}

