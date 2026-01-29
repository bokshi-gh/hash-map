#include "hash_map.h"

void hash_map_init(HashMap *m, size_t table_size)
{
    if (!m)
        return;

    m->table_size = table_size;
    m->hash_table = calloc(table_size, sizeof(Node *));
}

HashMap *hash_map_create(size_t table_size)
{
    HashMap *m = malloc(sizeof(HashMap));
    if (!m)
        return NULL;
    hash_map_init(m, table_size);
    return m;
}

void hash_map_put(HashMap *m, char *key, void *value)
{
    if (!m || !key)
        return;

    unsigned long hash = hash_fnv1a(key);
    size_t index = hash % m->table_size;

    Node *current = m->hash_table[index];

    // Update value if key exists
    while (current)
    {
        if (strcmp(current->key, key) == 0)
        {
            current->value = value;
            return;
        }
        current = current->next;
    }

    // Insert new node at head
    Node *n = malloc(sizeof(Node));
    n->key = strdup(key);
    n->value = value;
    n->next = m->hash_table[index];

    m->hash_table[index] = n;
}

void *hash_map_get(HashMap *m, char *key)
{
    if (!m || !key)
        return NULL;

    unsigned long hash = hash_fnv1a(key);
    size_t index = hash % m->table_size;

    Node *current = m->hash_table[index];
    while (current)
    {
        if (strcmp(current->key, key) == 0)
            return current->value;
        current = current->next;
    }

    return NULL;
}

void *hash_map_remove(HashMap *m, char *key)
{
    if (!m || !key)
        return NULL;

    unsigned long hash = hash_fnv1a(key);
    size_t index = hash % m->table_size;

    Node *current = m->hash_table[index];
    Node *prev = NULL;

    while (current)
    {
        if (strcmp(current->key, key) == 0)
        {
            void *value = current->value;

            if (prev == NULL)
            {
                m->hash_table[index] = current->next;
            }
            else
            {
                prev->next = current->next;
            }

            free(current);
            return value;
        }

        prev = current;
        current = current->next;
    }

    return NULL;
}

void hash_map_free(HashMap *m)
{
    if (!m)
        return;

    for (size_t i = 0; i < m->table_size; i++)
    {
        Node *current = m->hash_table[i];

        while (current)
        {
            Node *next = current->next;
            free(current);
            current = next;
        }
    }

    free(m->hash_table);
    free(m);
}

// djb2 Hash
unsigned long hash_djb2(const char *str)
{
    unsigned long long hash = 5381;
    int c;

    while ((c = *str++))
    {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return hash;
}

// FNV-1a Hash
unsigned long long hash_fnv1a(const char *str)
{
    unsigned long long hash = 14695981039346656037ULL; // 64-bit offset
    while (*str)
    {
        hash ^= (unsigned char)(*str++);
        hash *= 1099511628211ULL; // 64-bit FNV prime
    }
    return hash;
}
