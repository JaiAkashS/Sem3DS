#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_HEAP_SIZE 100

typedef struct {
    int *elements;
    int count;
} Heap;

void maxHeapifyUp(Heap *maxHeap, int index) {
    int parentIndex = (index - 1) / 2;
    if (index > 0 && maxHeap->elements[index] > maxHeap->elements[parentIndex]) {
        int temp = maxHeap->elements[index];
        maxHeap->elements[index] = maxHeap->elements[parentIndex];
        maxHeap->elements[parentIndex] = temp;
        maxHeapifyUp(maxHeap, parentIndex);
    }
}

void maxHeapifyDown(Heap *maxHeap, int index) {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int largest = index;

    if (leftChild < maxHeap->count && maxHeap->elements[leftChild] > maxHeap->elements[largest]) {
        largest = leftChild;
    }
    if (rightChild < maxHeap->count && maxHeap->elements[rightChild] > maxHeap->elements[largest]) {
        largest = rightChild;
    }
    if (largest != index) {
        int temp = maxHeap->elements[index];
        maxHeap->elements[index] = maxHeap->elements[largest];
        maxHeap->elements[largest] = temp;
        maxHeapifyDown(maxHeap, largest);
    }
}

void deleteFromMaxHeap(Heap *maxHeap) {
    if (maxHeap->count == 0) {
        printf("Heap is empty!\n");
        return;
    }
    maxHeap->elements[0] = maxHeap->elements[maxHeap->count - 1];
    maxHeap->count--;
    maxHeapifyDown(maxHeap, 0);
}

void insertToMaxHeap(Heap *maxHeap, int value) {
    if (maxHeap->count == MAX_HEAP_SIZE) {
        printf("Heap is full!\n");
        return;
    }
    maxHeap->elements[maxHeap->count] = value;
    maxHeapifyUp(maxHeap, maxHeap->count);
    maxHeap->count++;
}

void minHeapifyUp(Heap *minHeap, int index) {
    int parentIndex = (index - 1) / 2;
    if (index > 0 && minHeap->elements[index] < minHeap->elements[parentIndex]) {
        int temp = minHeap->elements[index];
        minHeap->elements[index] = minHeap->elements[parentIndex];
        minHeap->elements[parentIndex] = temp;
        minHeapifyUp(minHeap, parentIndex);
    }
}

void insertToMinHeap(Heap *minHeap, int value) {
    if (minHeap->count == MAX_HEAP_SIZE) {
        printf("Heap is full!\n");
        return;
    }
    minHeap->elements[minHeap->count] = value;
    minHeapifyUp(minHeap, minHeap->count);
    minHeap->count++;
}

void minHeapifyDown(Heap *minHeap, int index) {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int smallest = index;

    if (leftChild < minHeap->count && minHeap->elements[leftChild] < minHeap->elements[smallest]) {
        smallest = leftChild;
    }
    if (rightChild < minHeap->count && minHeap->elements[rightChild] < minHeap->elements[smallest]) {
        smallest = rightChild;
    }
    if (smallest != index) {
        int temp = minHeap->elements[index];
        minHeap->elements[index] = minHeap->elements[smallest];
        minHeap->elements[smallest] = temp;
        minHeapifyDown(minHeap, smallest);
    }
}

void deleteFromMinHeap(Heap *minHeap) {
    if (minHeap->count == 0) {
        printf("Heap is empty!\n");
        return;
    }
    minHeap->elements[0] = minHeap->elements[minHeap->count - 1];
    minHeap->count--;
    minHeapifyDown(minHeap, 0);
}
void printTree(int heapArray[], int size) {
    if (size == 0) {
        printf("Heap is empty!\n");
        return;
    }
    int levels = (int)(log2(size)) + 1;
    for (int i = 0; i < levels; i++) {
        int nodesOnLevel = pow(2, i);
        int spaceBetween = (int)(pow(2, levels - i) - 1);
        for (int j = 0; j < nodesOnLevel && (nodesOnLevel - 1 + j) < size; j++) {
            int index = nodesOnLevel - 1 + j;
            if (j == 0) {
                printf("%*s%d", spaceBetween / 2, "", heapArray[index]);
            } else {
                printf("%*s%d", spaceBetween, "", heapArray[index]);
            }
        }
        printf("\n");
    }
}
void displayMinHeap(Heap *minHeap) {
    if (minHeap->count == 0) {
        printf("Heap is empty!\n");
        return;
    }
    printf("Min Heap Tree Representation:\n");
    printTree(minHeap->elements, minHeap->count);
}

void displayMaxHeap(Heap *maxHeap) {
    if (maxHeap->count == 0) {
        printf("Heap is empty!\n");
        return;
    }
    printf("Max Heap Tree Representation:\n");
    printTree(maxHeap->elements, maxHeap->count);
}

int main() {
    Heap *maxHeap = (Heap *)malloc(sizeof(Heap));
    Heap *minHeap = (Heap *)malloc(sizeof(Heap));
    maxHeap->elements = (int *)malloc(MAX_HEAP_SIZE * sizeof(int));
    minHeap->elements = (int *)malloc(MAX_HEAP_SIZE * sizeof(int));
    maxHeap->count = 0;
    minHeap->count = 0;

    int heapType, choice, value;
    printf("Choose Heap Type: 1 for Max Heap, 2 for Min Heap: ");
    scanf("%d", &heapType);

    if (heapType != 1 && heapType != 2) {
        printf("Invalid heap type!\n");
        return 1;
    }

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                if (heapType == 1) {
                    insertToMaxHeap(maxHeap, value);
                } else if (heapType == 2) {
                    insertToMinHeap(minHeap, value);
                }
                break;
            case 2:
                if (heapType == 1) {
                    deleteFromMaxHeap(maxHeap);
                } else if (heapType == 2) {
                    deleteFromMinHeap(minHeap);
                }
                break;
            case 3:
                if (heapType == 1) {
                    displayMaxHeap(maxHeap);
                } else if (heapType == 2) {
                    displayMinHeap(minHeap);
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}


