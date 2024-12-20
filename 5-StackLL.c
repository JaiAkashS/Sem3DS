#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>


struct Node{
	int data;
	struct Node *next;
};

typedef struct Node *position;

int isEmpty(struct Node *head){
	return (head==NULL);
}


position createnode(int element){
	struct Node *tempnode;
	tempnode=(struct Node *)malloc(sizeof(struct Node));
	if(tempnode==NULL){
		printf("Error");
	}
	tempnode->data=element;   
	tempnode->next=NULL;
	return tempnode;
}

void push(int num,struct Node **head){
	struct Node *newNode = createnode(num);
	newNode->next = *head;
	*head = newNode;
}

void pop(struct Node **head){
	if(!isEmpty(*head)){
		int num = (*head)->data;
		struct Node *temp = *head;
		*head = (*head)->next;
		free(temp);	
		printf("%d is Popped",num);
	}
	else {
		printf("Empty Stack");
	}
}

void peek(struct Node **head){
	if(!isEmpty(*head)){
		printf("Top of Stack:%d\n",(*head)->data);
	}
	else {
		printf("Empty Stack\n");
	}
}

void display(struct Node *head){
	struct Node *pos=head;
	printf("Top:");
	while(pos!=NULL){
		printf("%d ->",pos->data);
		pos=pos->next;
	}
	printf("NULL\n");
}

int main(){
	int num1,ch,flag=1;
	struct Node *s1=NULL;
	while(flag){
		printf("Menu\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
		printf("Enter your Choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1:{
				printf("\nEnter Num:");
				scanf("%d",&num1);
    			push(num1,&s1);
				break;
			}
			case 2:{
				pop(&s1);
				break;
			}
			case 3:{
				peek(&s1);
				break;
			}
			case 4:{
				display(s1);
				break;
			}
			case 5:{
				flag = 0;
				break;
			}
			default:{
				printf("Invalid Choice!");
				break;
			}
		}
	}
	return 0;
}