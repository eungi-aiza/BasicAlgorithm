#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define TABLE_SIZE 1000

typedef struct Node {
    char key[100];
    int value;
    bool deleted;
} Node;

typedef struct HashMap {
    Node* table[TABLE_SIZE];
} HashMap;

void initHashMap(HashMap* map) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        map->table[i] = NULL;
    }
}

int hashFunc(const char* key, int attempt) {
    int sum = 0;
    while (*key) {
        sum += *key;
        key++;
    }
    return (sum + attempt) % TABLE_SIZE;
}

void insert(HashMap* map, const char* key, int value) {
    int attempt = 0;
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->key, key);
    newNode->value = value;
    newNode->deleted = false;

    while (1) {
        int idx = hashFunc(key, attempt);
        if (!map->table[idx] || map->table[idx]->deleted) {
            map->table[idx] = newNode;
            return;
        }
        attempt++;
    }
}

bool get(const HashMap* map, const char* key, int* value) {
    int attempt = 0;
    while (1) {
        int idx = hashFunc(key, attempt);
        if (!map->table[idx]) return false;
        if (strcmp(map->table[idx]->key, key) == 0 && !map->table[idx]->deleted) {
            *value = map->table[idx]->value;
            return true;
        }
        attempt++;
    }
}

void removeKey(HashMap* map, const char* key) {
    int attempt = 0;
    while (1) {
        int idx = hashFunc(key, attempt);
        if (!map->table[idx]) return;
        if (strcmp(map->table[idx]->key, key) == 0 && !map->table[idx]->deleted) {
            map->table[idx]->deleted = true;
            return;
        }
        attempt++;
    }
}

int main() {
    HashMap map;
    initHashMap(&map);
    insert(&map, "one", 1);
    insert(&map, "two", 2);
    int value;
    if (get(&map, "one", &value)) {
        printf("one: %d\n", value);
    }
    removeKey(&map, "one");
    if (!get(&map, "one", &value)) {
        printf("one not found\n");
    }
    return 0;
}