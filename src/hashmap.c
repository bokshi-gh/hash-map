#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashmap.h"

// Simple string hash function (djb2)
unsigned int hashFunction(void* key) {
    char* str = (char*)key;
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    return hash % TABLE_SIZE;
}

HashMap* createHashMap() {
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    for (int i = 0; i < TABLE_SIZE; i++)
        map->hash_table[i] = NULL;
    return map;
}

void insert(HashMap* map, void* key, void* value) {
    int index = hashFunction(key);

    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->value = value;
    node->next = map->hash_table[index];
    map->hash_table[index] = node;
}

void* search(HashMap* map, void* key) {
    int index = hashFunction(key);
    Node* node = map->hash_table[index];

    while (node != NULL) {
        if (strcmp((char*)key, (char*)node->key) == 0)
            return node->value;
        node = node->next;
    }
    return NULL;
}

void deleteKey(HashMap* map, void* key) {
    int index = hashFunction(key);
    Node* node = map->hash_table[index];
    Node* prev = NULL;

    while (node != NULL) {
        if (strcmp((char*)key, (char*)node->key) == 0) {
            if (prev == NULL)
                map->hash_table[index] = node->next;
            else
                prev->next = node->next;
            free(node); // free memory
            return;
        }
        prev = node;
        node = node->next;
    }
}

void freeHashMap(HashMap* map) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* node = map->hash_table[i];
        while (node != NULL) {
            Node* temp = node;
            node = node->next;
            free(temp);
        }
    }
    free(map);
}
