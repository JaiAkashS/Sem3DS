#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX 100

int top = -1, a[MAX];

void push(char x) { 
    a[++top] = x;
}

char pop() {
    if (top == -1)
        return -1;
    else
        return a[top--];
}

int prcd(char c) {
    if (c == '(')
        return 0;
    else if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    return -1;  
}

void intopost(char infix[MAX], char postfix[MAX]) {
    char temp, x;
    int i = 0, j = 0;
    while (infix[i] != '\0') {
        temp = infix[i];
        
        if (isalnum(temp)) {
            postfix[j++] = temp;
        } else if (temp == '(') {
            push(temp);
        } else if (temp == ')') {
            while ((x = pop()) != '(') {
                postfix[j++] = x;
            }
        } else {
            while (top != -1 && prcd(a[top]) >= prcd(temp)) {
                postfix[j++] = pop();
            }
            push(temp);
        }
        i++;
    }

    while (top != -1)
        postfix[j++] = pop();
    
    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter the infix expression: ");
    fgets(infix, MAX, stdin);
    infix[strcspn(infix, "\n")] = 0;
    intopost(infix, postfix);
    printf("The postfix expression is: %s\n", postfix);
    
    return 0;
}
