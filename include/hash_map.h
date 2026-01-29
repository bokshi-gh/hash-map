#ifndef HASH_MAP_H
#define HASH_MAP_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Node struct for linked list (chaining)
typedef struct Node {
    char *key;
    void *value;
    struct Node *next;
} Node;

// HashMap struct
typedef struct {
    Node **hash_table;
    size_t table_size;
} HashMap;

// HashMap functions
void hash_map_init(HashMap *m, size_t table_size);
HashMap* hash_map_create(size_t table_size);
void hash_map_put(HashMap *m, char *key, void *value);
void* hash_map_get(HashMap *m, char *key);
void* hash_map_remove(HashMap *m, char *key);
void hash_map_free(HashMap *m);

// Hash functions
unsigned long hash_djb2(const char *str);
unsigned long long hash_fnv1a(const char *str);

#endif
