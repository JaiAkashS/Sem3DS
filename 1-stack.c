#include <stdio.h>

#define EmptyTop -1
#define MinStackSize 5

int stack[MinStackSize];
int Top=EmptyTop,size=MinStackSize;

void MakeEmpty(){
    Top=EmptyTop;
}

int IsFull(){
    return Top==size-1;
}

int IsEmpty(){
    return Top==EmptyTop;
}

void push(int num){
    if(IsFull()){
        printf("Error:Stack is full");
    }
    else {
        stack[++Top]=num;
    }
}

int TopofStack(){
    if (!IsEmpty()) {
        return stack[Top];
    }
    printf("Error:Empty Stack");
    return 0;
}


void pop(){
    if(IsEmpty()){
        printf("Error:Stack is empty");
    }
    else {
        printf("\nElement Popped:%d\n",stack[Top]);
        Top--;
    }
}

void display(){
    int i=Top;
    printf("Stack:\n");
    while (i>=0) {
        printf("%d\n",stack[i]);
        --i;
    }
}

int main(){
    int ch, num1, flag = 1, pos;
    while (flag) {
        printf("\nMENU\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\nEnter a Choice:");
        scanf("%d", &ch);
        switch (ch) {
        case 1: {
            printf("Enter a Num:");
            scanf("%d",&num1);
            push(num1);
            break;
        }
        case 2: {
            pop();
            break;
        }
        case 3: {
            printf("\nTop of Stack:%d\n",TopofStack());
            break;
        }
        case 4: {
            printf("\n");
            display();
            break;
        }
        case 5: {
            flag = 0;
            break;
        }
        }
    }
    return 0;
}
