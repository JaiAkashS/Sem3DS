#include <stdio.h>

void sort(int array[], int size) {
    int i,j,temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int array[],int size,int search){
    int low=0,mid,high=size-1;
    while (low<=high) {
        mid = (low+high)/2;
        if (array[mid]==search) {
            return mid;
        }else if (array[mid]>search) {
            high=mid-1;
        }
        else if (array[mid]<search) {
            low=mid+1;
        } 
    }
    return -1;
}

int main(){
    int i,pos,n,target;
    int arr[100];
    printf("Enter Array Size:");
    scanf("%d",&n);
    for (i=0;i<n;++i) {
        printf("Enter Element %d:",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Sorted Array:");
    sort(arr,n);
    for (i=0;i<n;++i) {
        printf("%d ",arr[i]);
    }
    printf("\nEnter Search Element:");
    scanf("%d",&target);
    pos=binarySearch(arr,n,target);
    if(pos!=-1){
        printf("Element Found at position %d",pos+1);
    }else {
        printf("Element not found");
    }
    return 0;
}