#pragma once

#define TABLE_SIZE 1049

typedef struct Node {
    void* key;
    void* value;
    struct Node* next;
} Node;

typedef struct HashMap {
    Node* hash_table[TABLE_SIZE];
} HashMap;

unsigned int hashFunction(void* key);
HashMap* createHashMap();
void insert(HashMap* map, void* key, void* value);
void* search(HashMap* map, void* key);
void deleteKey(HashMap* map, void* key);
void freeHashMap(HashMap* map);

