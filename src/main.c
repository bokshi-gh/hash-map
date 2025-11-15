#include "hash_map.h"
#include <stdio.h>

int main() {
    // Create hashmap
    HashMap *map = hash_map_create(10);

    // Insert key-value pairs
    hash_map_put(map, "apple", "red");
    hash_map_put(map, "banana", "yellow");
    hash_map_put(map, "grape", "purple");

    // Retrieve
    printf("apple = %s\n", (char*)hash_map_get(map, "apple"));
    printf("banana = %s\n", (char*)hash_map_get(map, "banana"));

    // Update
    hash_map_put(map, "banana", "green");
    printf("banana (updated) = %s\n", (char*)hash_map_get(map, "banana"));

    // Remove
    char *removed = (char*)hash_map_remove(map, "grape");
    printf("Removed grape = %s\n", removed);

    printf("grape = %s\n", (char*)hash_map_get(map, "grape")); // Should be NULL

    // Free map
    hash_map_free(map);

    return 0;
}