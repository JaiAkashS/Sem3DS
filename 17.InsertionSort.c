#include <stdio.h>

void insertionSort(int arr[],int size){
    int key;
    for(int i=1;i<size;++i){
        key=arr[i];
        int j = i-1;
        while(j>=0 && key<arr[j]){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
void display(int arr[],int size){
    int i;
    for(int i=0;i<size;++i){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main() {
    int n,i,arr[100];
    printf("Enter Array Size:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Element %d:",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Array before Sorting:");
    display(arr,n);
    insertionSort(arr,n);
    printf("Array After Sorting:");
    display(arr,n);
}
