#include <stdio.h>
#include <stdlib.h>
#include "hashmap.h"

int main() {
    // Create a hash map
    HashMap* map = createHashMap();

    // Insert string values
    insert(map, "apple", "red");
    insert(map, "banana", "yellow");
    insert(map, "grape", "purple");

    // Insert integer values (demonstrating generic void* values)
    int* num1 = malloc(sizeof(int));
    *num1 = 42;
    insert(map, "answer", num1);

    int* num2 = malloc(sizeof(int));
    *num2 = 100;
    insert(map, "hundred", num2);

    // Search for string values
    char* color = (char*)search(map, "banana");
    if (color != NULL) 
        printf("banana -> %s\n", color);

    color = (char*)search(map, "grape");
    if (color != NULL)
        printf("grape -> %s\n", color);

    // Search for integer values
    int* val = (int*)search(map, "answer");
    if (val != NULL)
        printf("answer -> %d\n", *val);

    val = (int*)search(map, "hundred");
    if (val != NULL)
        printf("hundred -> %d\n", *val);

    // Delete a key
    deleteKey(map, "apple");
    color = (char*)search(map, "apple");
    if (color == NULL)
        printf("apple has been deleted\n");

    // Clean up
    free(num1);
    free(num2);
    freeHashMap(map);

    return 0;
}

