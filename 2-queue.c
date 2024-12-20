#include <stdio.h>

#define MinQueueSize 5

int Queue[MinQueueSize];
int rear,front,size=MinQueueSize;

int IsFull(){
    return rear==size-1;
}

int isEmpty(){
    return front==-1;
}
void MakeEmpty(){
    front=-1;
    rear=-1;
}

void Enqueue(int num){
    if(IsFull()){
        printf("Error:Full Queue");
    }else {
        if(front==-1){
            front=0;
        }
        rear++;
        Queue[rear]=num;
    }
}

void Dequeue(){
    int num;
    if(isEmpty()){
        printf("Queue is Empty!");
    }
    else{
        num=Queue[front];
        front++;
        if(front>rear){
            front=-1;
            rear=-1;
        }
        printf("%d is Dequeued\n",num);
    }
}

void display(){
    int i=front;
    if(front==-1){
        printf("Queue is Empty!");
        return;
    }
    printf("\nQueue\n");
    while(i<=rear){
        printf("%d\n",Queue[i]);
        i++;
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