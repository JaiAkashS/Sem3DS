#include <stdio.h>

void selectionSort(int arr[],int size){
    int i,j,min,temp;
    for(i=0;i<size;++i){
        min=i;
        for(j=i+1;j<size;++j){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        if(min!=i){
            temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}
void display(int array[],int size){
    for(int i=0;i<size;++i){
        printf("%d ",array[i]);
    }
    printf("\n");
}
int main(){
    int n,i,arr[100];
    printf("Enter Array Size:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Element %d:",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Array before Sorting:");
    display(arr,n);
    selectionSort(arr,n);
    printf("Array After Sorting:");
    display(arr,n); 
    return 0;
}