#include <stdio.h>

int linearSearch(int array[],int size,int search){
    int i=0;
    while(i<size){
        if(array[i]==search){
            return i;
        }
        ++i;
    }
    return -1;
}

int main(){
    int n,i,target,pos;
    int arr[100];
    printf("Enter Array Size:");
    scanf("%d",&n);
    for (i=0;i<n;++i) {
        printf("Enter Element %d:",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Enter Search Element:");
    scanf("%d",&target);
    pos=linearSearch(arr,n,target);
    if(pos!=-1){
        printf("Element Found at position %d",pos+1);
    }else {
        printf("Element not found");
    }
    return 0;
}

