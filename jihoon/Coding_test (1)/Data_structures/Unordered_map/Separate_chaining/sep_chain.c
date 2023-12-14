#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 1000
#define KEY_MAX_LENGTH 100

typedef struct Node {
    char key[KEY_MAX_LENGTH];
    int value;
    struct Node* next;
} Node;

typedef struct {
    Node* buckets[TABLE_SIZE];
} HashMap;

int hashFunc(const char* key) {
    int sum = 0;
    while (*key) {
        sum += *key++;
    }
    return sum % TABLE_SIZE;
}

HashMap* createMap() {
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    for (int i = 0; i < TABLE_SIZE; i++) {
        map->buckets[i] = NULL;
    }
    return map;
}

void insert(HashMap* map, const char* key, int value) {
    int hashValue = hashFunc(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->key, key);
    newNode->value = value;
    newNode->next = NULL;

    if (!map->buckets[hashValue]) {
        map->buckets[hashValue] = newNode;
    } else {
        Node* current = map->buckets[hashValue];
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

int get(const HashMap* map, const char* key, int* value) {
    int hashValue = hashFunc(key);
    Node* current = map->buckets[hashValue];
    while (current) {
        if (strcmp(current->key, key) == 0) {
            *value = current->value;
            return 1; // Found
        }
        current = current->next;
    }
    return 0; // Not found
}

void removeKey(HashMap* map, const char* key) {
    int hashValue = hashFunc(key);
    Node* current = map->buckets[hashValue];
    Node* prev = NULL;

    while (current) {
        if (strcmp(current->key, key) == 0) {
            if (prev) {
                prev->next = current->next;
            } else {
                map->buckets[hashValue] = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

int main() {
    HashMap* map = createMap();
    insert(map, "one", 1);
    insert(map, "two", 2);
    int value;
    if (get(map, "one", &value)) {
        printf("one: %d\n", value);
    }
    removeKey(map, "one");
    if (!get(map, "one", &value)) {
        printf("one not found\n");
    }
    // TODO: Free all allocated memory
    return 0;
}