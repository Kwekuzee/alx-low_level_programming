void hash_table_print(const hash_table_t *ht)
{
    unsigned long int i;
    hash_node_t *tmp;
    int first_node = 1;

    if (ht == NULL)
        return;

    printf("{");
    for (i = 0; i < ht->size; i++)
    {
        tmp = ht->array[i];
        while (tmp != NULL)
        {
            if (first_node == 0)
                printf(", ");
            printf("'%s': '%s'", tmp->key, tmp->value);
            first_node = 0;
            tmp = tmp->next;
        }
    }
    printf("}\n");
}

