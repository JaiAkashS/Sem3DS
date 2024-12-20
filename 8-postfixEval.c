#include <ctype.h>
#include <stdio.h>

#define MAX 20

int Top = -1;
int stack[MAX];
char input[100];

void push(int element) {
  if (Top == MAX - 1) {
    printf("Stack is Full!");
    return;
  } else {
    stack[++Top] = element;
  }
}

int pop() {
  if (Top == -1) {
    printf("Empty Stack!");
    return -1;
  } else {
    int res = stack[Top];
    Top--;
    return res;
  }
}

int operation(char op, int num1, int num2) {
  int res;
  switch (op) {
  case '+':
    return num1 + num2;
    break;
  case '-':
    return num1 - num2;
    break;
  case '*':
    return num1 * num2;
  case '/':
    return num1 / num2;
  }
}

void eval() {
  int num1, num2, i = 0;
  char ip;
  while (input[i] != '\0') {
    ip = input[i];
    if (ip == '$') {
      break;
    } else if (isdigit(ip)) {
      push(ip - '0');
    } else if (!isalnum(ip)) {
      num2 = pop();
      num1 = pop();
      push(operation(ip, num1, num2));
    }
    i++;
  }
  printf("%d is the result!", pop());
}

int main() {
  printf("Enter Expression:");
  scanf("%s", input);
  eval();
  return 0;
}
