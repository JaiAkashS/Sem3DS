#include <stdio.h>

#define MinQueueSize 3

int Queue[MinQueueSize];
int front,rear,capacity,size=MinQueueSize;

int IsFull(){
    return capacity==size;
}

int isEmpty(){
    return capacity==0;
}
void MakeEmpty(){
    front=-1;
    rear=-1;
    capacity=0;
}

void Enqueue(int num){
    if(IsFull()){
        printf("Error:Full Queue");
    }else {
        if(front==-1){
            front=0;
        }
        rear=(rear+1)%size;
        Queue[rear]=num;
        capacity++;
    }
}

void Dequeue(){
    int num;
    if(isEmpty()){
        printf("Queue is Empty!");
    }
    else{
        num=Queue[front];
        front=(front+1)%size;
        capacity--;
        if(capacity==0){
            front=-1;
            rear=-1;
        }
        printf("%d is Dequeued",num);
    }
}

void display(){
    int i=front;
    if(front==-1){
        printf("Queue is Empty!");
        return;
    }
    printf("\nQueue\n");
    for(int j=1;j<=capacity;j++){
        printf("%d\n",Queue[i]);
        i=(i+1)%size;
    }
}

int main(){
    int num1,ch,flag=1;
    MakeEmpty();
    while (flag) {
        printf("\nMENU\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter a Choice:");
        scanf("%d", &ch);
        switch (ch) {
        case 1: {
            printf("Enter a Num:");
            scanf("%d",&num1);
            Enqueue(num1);
            break;
        }
        case 2: {
            Dequeue();
            break;
        }
        case 3: {
            display();
            break;
        }
        case 4: {
            flag = 0;
            break;
        }
        }
    }
    return 0;
}
