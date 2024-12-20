#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

struct Node *front=NULL,*rear=NULL;

void enqueue(int num){
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data=num;
	newNode->next=NULL;
	if(rear==NULL){
		front=rear=newNode;
	}else{
		rear->next=newNode;
		rear=newNode;
	}
}

void dequeue(){
	if(rear==NULL){
		printf("Queue is Empty");	
	}
	else{
		int result = front->data;
		struct Node *ptr =front;
		front=front->next;
		free(ptr);
		printf("%d is Dequeued\n",result);
	}
}

void display(){
	if(front==NULL){
		printf("Queue is Empty!");
	}
	else{
		struct Node *ptr = front;
		while(ptr!=NULL){
			printf("%d ->",ptr->data);
			ptr = ptr->next;
		}
		printf("NULL\n");
	}
}



int main(){
	int num1,ch,flag=1;
	while(flag){
		printf("\nMenu\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1:{
				printf("\nEnter num:");
				scanf("%d",&num1);
				enqueue(num1);
				break;
			}
			case 2:{
				dequeue();
				break;
			}
			case 3:{
				display();
				break;
			}
			case 4:{
				flag=0;
				break;
			}
			default:{
				printf("Invalid");
				break;
			}
		}
	}
}
