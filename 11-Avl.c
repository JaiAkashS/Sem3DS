#include <stdio.h>
#include <stdlib.h>
struct Node {
    int el;
    struct Node *left;
    struct Node *right;
    int height;
};
struct Node *createNode(int el) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->el = el;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}
int max(int a, int b) { return a > b ? a : b; }
int height(struct Node *node) {
    if (node == NULL)
        return 0;
    return node->height;
}
int getBalance(struct Node *node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}
struct Node *LL(struct Node *y) {
    struct Node *x = y->left;
    struct Node *T2 = x->right;
    y->left = T2;
    x->right = y;
    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));
    return x;
}
struct Node *RR(struct Node *x) {
    struct Node *y = x->right;
    struct Node *T2 = y->left;
    x->right = T2;
    y->left = x;
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));
    return y;
}
struct Node *insert(struct Node *node, int el) {
    if (node == NULL)
        return createNode(el);
    if (el < node->el)
        node->left = insert(node->left, el);
    else if (el > node->el)
        node->right = insert(node->right, el);
    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);
    if (balance > 1 && el < node->left->el) {
        return LL(node);
    }
    if (balance < -1 && el > node->right->el) {
        return RR(node);
    }
    if (balance > 1 && el > node->left->el) {
        node->left = RR(node->left);
        return LL(node);
    }
    if (balance < -1 && el < node->right->el) {
        node->right = LL(node->right);
        return RR(node);
    }
    return node;
}
void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->el);
        inorder(root->right);
    }
}
void postorder(struct Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->el);
    }
}
void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->el);
        preorder(root->left);
        preorder(root->right);
    }
}
int main() {
    struct Node *root = NULL;
    int choice, value;
    while (1) {
        printf("\nMENU:\n1)Insert\n2)Inorder\n3)Postorder\n4)Preorder\n5)Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("\nEnter value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            break;
        case 2:
            printf("In-order Traversal: ");
            inorder(root);
            printf("\n");
            break;
        case 3:
            printf("Post-order Traversal: ");
            postorder(root);
            printf("\n");
            break;
        case 4:
            printf("Pre-order Traversal: ");
            preorder(root);
            printf("\n");
            break;
        case 5:
            printf("Exiting...");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}