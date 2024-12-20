#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>


struct Node {
  int num;
  struct Node *next;
};
typedef struct Node node;
typedef struct Node *nodeptr;

nodeptr findPrev(int data, nodeptr head) {
  nodeptr p = head;
  while (p->next != NULL && p->next->num != data) {
    p = p->next;
  }
  return p;
}

int isLast(nodeptr p) { return p->next == NULL; }

struct Node *createNode(int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  if (newNode == NULL) {
    printf("\nError Creating Node!");
  }
  newNode->num = data;
  newNode->next = NULL;
  return newNode;
}

void display(struct Node *head) {
  struct Node *p = head->next;
  while (p != NULL) {
    printf("%d -> ", p->num);
    p = p->next;
  }
  printf("NULL\n\n");
}

void insertBeg(int data, nodeptr head) {
  nodeptr Tempnode;
  Tempnode = createNode(data);
  Tempnode->next = head->next;
  head->next = Tempnode;
}

void insertLast(int data, nodeptr head) {
  nodeptr Tempnode, p;
  Tempnode = createNode(data);
  p = head->next;
  while (!isLast(p)) {
    p = p->next;
  }
  p->next = Tempnode;
  Tempnode->next = NULL;
}

void insertatPos(int data, int pos, nodeptr head) {
  int i = 1;
  nodeptr Tempnode, prev = head;
  Tempnode = createNode(data);
  while (prev->next != NULL && i < pos) {
    prev = prev->next;
    ++i;
  }
  if (prev == NULL) {
    printf("\nInvalid Positon");
    return;
  }
  Tempnode->next = prev->next;
  prev->next = Tempnode;
}

void deleteNum(int data, nodeptr head) {
  nodeptr prev, Tempnode;
  prev = findPrev(data, head);
  if (!isLast(prev)) {
    Tempnode = prev->next;
    prev->next = Tempnode->next;
    free(Tempnode);
  }
}

void deleteBeg(nodeptr head) {
  nodeptr Tempnode = head->next;
  head->next = Tempnode->next;
  free(Tempnode);
}

void deleteLast(nodeptr head) {
  nodeptr temp, p = head->next;
  while (p->next->next != NULL) {
    p = p->next;
  }
  temp = p->next;
  p->next = NULL;
  free(temp);
}
void deleteAtPos(int position, nodeptr head) {
  nodeptr temp, p = head;
  int i = 1;
  while (p->next != NULL && i < position) {
    p = p->next;
    ++i;
  }
  temp = p->next;
  if (p == NULL) {
    printf("\nInvalid Positon");
    return;
  }
  p->next = temp->next;
  free(temp);
}

int find(int search, nodeptr head) {
  int pos = 0;
  nodeptr p = head->next;
  while (p->next != NULL && p->num != search) {
    p = p->next;
    pos++;
  }
  printf("Address :%p\n",&p);
  return pos;
}

void append(int data, nodeptr head) {
  nodeptr temp = createNode(data);
  temp->next = head->next;
  head->next = temp;
}

int main() {
  int ch, num1, flag = 1, pos;
  nodeptr head = createNode(0);
  while (flag) {
    printf("MENU\n1.Insert at beginning\n2.Insert at last\n3.Insert at "
           "Position\n4.Delete from beginning\n5.Delete from last\n6.Delete "
           "node at Postion\n7.Delete Element\n8.Search for an "
           "element\n9.Show\n10.Exit\nEnter a Choice:");
    scanf("%d", &ch);
    switch (ch) {
    case 1: {
      printf("\nEnter a Num:");
      scanf("%d", &num1);
      insertBeg(num1, head);
      display(head);
      break;
    }
    case 2: {
      printf("\nEnter a Num:");
      scanf("%d", &num1);
      insertLast(num1, head);
      display(head);
      break;
    }
    case 3: {
      printf("\nEnter a Num:");
      scanf("%d", &num1);
      printf("\nEnter Position:");
      scanf("%d", &pos);
      insertatPos(num1, pos, head);
      display(head);
      break;
    }
    case 4: {
      deleteBeg(head);
      display(head);
      break;
    }
    case 5: {
      deleteLast(head);
      display(head);
      break;
    }
    case 6: {
      printf("\nEnter Position:");
      scanf("%d", &pos);
      deleteAtPos(pos, head);
      display(head);
      break;
    }
    case 7:{
      printf("\nEnter Element:");
      scanf("%d", &num1);
      deleteNum(num1,head);
      display(head);
      break;
    }
    case 8: {
      int idx = -1;
      printf("\nEnter a Num:");
      scanf("%d", &num1);
      idx = find(num1, head);
      printf("%d found at index %d\n", num1, idx);
      break;
    }
    case 9: {
      display(head);
      break;
    }
    case 10: {
      flag = 0;
      break;
    }
    }
  }
  return 0;
}
