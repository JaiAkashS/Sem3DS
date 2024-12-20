#include <stdio.h>
#include <stdlib.h>
#define HASH_SIZE 10

void insertIntoHash(int element, int hashTable[]) {
    int index = element % HASH_SIZE;
    int i = 1;

    while (hashTable[index] != -1) {
        index = (index + i * i) % HASH_SIZE;
        i++;
        if (index == HASH_SIZE) {
            printf("Hash table is full, cannot insert %d\n", element);
            return;
        }
    }
    hashTable[index] = element;
}

void searchInHash(int element, int hashTable[]) {
    int index = element % HASH_SIZE;
    int i = 1;

    while (hashTable[index] != -1) {
        if (hashTable[index] == element) {
            printf("Element %d found at index %d\n", element, index);
            return;
        } else {
            index = (index + i * i) % HASH_SIZE;
            i++;
            if (i == HASH_SIZE) {
                break;
            }
        }
    }
    printf("Element %d not found\n", element);
}

int main() {
    int elements[100], numElements, i, hashTable[HASH_SIZE], searchElement;

    for (i = 0; i < HASH_SIZE; i++) {
        hashTable[i] = -1;
    }

    printf("Enter the number of elements: ");
    scanf("%d", &numElements);
    printf("Enter the elements: ");
    for (i = 0; i < numElements; i++) {
        scanf("%d", &elements[i]);
        insertIntoHash(elements[i], hashTable);
    }

    printf("\nHash Table Contents:\n");
    for (i = 0; i < HASH_SIZE; i++) {
        if (hashTable[i] == -1) {
            printf("Index %d: empty\n", i);
        } else {
            printf("Index %d: %d\n", i, hashTable[i]);
        }
    }

    printf("Enter the element to search: ");
    scanf("%d", &searchElement);
    searchInHash(searchElement, hashTable);

    return 0;
}
