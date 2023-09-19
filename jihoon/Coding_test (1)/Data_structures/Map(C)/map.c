#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100 // Maximum number of elements in the map

typedef struct Dictionary {
    int size; // Current number of elements in the map
    char keys[MAX_SIZE][100]; // Array to store the keys
    int values[MAX_SIZE]; // Array to store the values
} Dictionary;

void initDictionary(Dictionary* dict) {
    dict->size = 0;
}

int getIndex(const Dictionary* dict, const char key[]) {
    for (int i = 0; i < dict->size; i++) {
        if (strcmp(dict->keys[i], key) == 0) {
            return i;
        }
    }
    return -1; // Key not found
}

void insert(Dictionary* dict, const char key[], int value) {
    int index = getIndex(dict, key);
    if (index == -1) { // Key not found
        strcpy(dict->keys[dict->size], key);
        dict->values[dict->size] = value;
        dict->size++;
    } else { // Key found
        dict->values[index] = value;
    }
}

int get(const Dictionary* dict, const char key[]) {
    int index = getIndex(dict, key);
    if (index == -1) { // Key not found
        return -1;
    } else { // Key found
        return dict->values[index];
    }
}

void printMap(const Dictionary* dict) {
    for (int i = 0; i < dict->size; i++) {
        printf("%s: %d\n", dict->keys[i], dict->values[i]);
    }
}

int main() {
    Dictionary dict1;
    initDictionary(&dict1);
    insert(&dict1, "One", 1);
    insert(&dict1, "Two", 2);
    insert(&dict1, "Three", 3);

    printf("VALUE OF COMPLETE MAP : \n");
    printMap(&dict1);

    printf("\nValue of Three: %d\n", get(&dict1, "Three"));

    Dictionary dict2;
    initDictionary(&dict2);
    insert(&dict2, "Apple", 5);
    insert(&dict2, "Banana", 3);

    printf("\nVALUE OF ANOTHER MAP : \n");
    printMap(&dict2);

    return 0;
}