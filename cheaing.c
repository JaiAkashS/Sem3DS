#include <stdio.h>
#include <stdlib.h>

struct polynomial {
    float coeff;
    int pow;
    struct polynomial *next;
};

struct polynomial *poly1 = NULL, *poly2 = NULL, *poly = NULL;


void createExp(struct polynomial **node) {
    int n, i;
    struct polynomial *temp;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        struct polynomial *newNode = (struct polynomial *)malloc(sizeof(struct polynomial));
        printf("Enter coefficient for term %d: ", i + 1);
        scanf("%f", &newNode->coeff);
        printf("Enter exponent for term %d: ", i + 1);
        scanf("%d", &newNode->pow);
        newNode->next = NULL;

        if (*node == NULL) {
            *node = newNode;
            temp = *node;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }
}


void displayExp(struct polynomial *node) {
    while (node != NULL) {
        printf("%.1fx^%d", node->coeff, node->pow);
        node = node->next;
        if (node != NULL) {
            printf(" + ");
        }
    }
}


void polyadd(struct polynomial *poly1, struct polynomial *poly2, struct polynomial **poly) {
    struct polynomial *temp = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        struct polynomial *newNode = (struct polynomial *)malloc(sizeof(struct polynomial));
        if (poly1->pow > poly2->pow) {
            newNode->pow = poly1->pow;
            newNode->coeff = poly1->coeff;
            poly1 = poly1->next;
        } else if (poly1->pow < poly2->pow) {
            newNode->pow = poly2->pow;
            newNode->coeff = poly2->coeff;
            poly2 = poly2->next;
        } else {
            newNode->pow = poly1->pow;
            newNode->coeff = poly1->coeff + poly2->coeff;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        newNode->next = NULL;
        if (*poly == NULL) {
            *poly = newNode;
            temp = *poly;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }

    while (poly1 != NULL) {
        struct polynomial *newNode = (struct polynomial *)malloc(sizeof(struct polynomial));
        newNode->pow = poly1->pow;
        newNode->coeff = poly1->coeff;
        newNode->next = NULL;
        poly1 = poly1->next;

        if (*poly == NULL) {
            *poly = newNode;
            temp = *poly;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }

    while (poly2 != NULL) {
        struct polynomial *newNode = (struct polynomial *)malloc(sizeof(struct polynomial));
        newNode->pow = poly2->pow;
        newNode->coeff = poly2->coeff;
        newNode->next = NULL;
        poly2 = poly2->next;

        if (*poly == NULL) {
            *poly = newNode;
            temp = *poly;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }
}

void polymultiply(struct polynomial *poly1, struct polynomial *poly2, struct polynomial **poly) {
    struct polynomial *temp1 = poly1, *temp2;
    struct polynomial *result = NULL;

    while (temp1 != NULL) {
        temp2 = poly2;
        while (temp2 != NULL) {
            struct polynomial *newNode = (struct polynomial *)malloc(sizeof(struct polynomial));
            newNode->coeff = temp1->coeff * temp2->coeff;
            newNode->pow = temp1->pow + temp2->pow;
            newNode->next = NULL;

            struct polynomial *temp = *poly, *prev = NULL;
            while (temp != NULL && temp->pow > newNode->pow) {
                prev = temp;
                temp = temp->next;
            }

            if (temp != NULL && temp->pow == newNode->pow) {
                temp->coeff += newNode->coeff;
                free(newNode);
            } else {
                if (prev == NULL) {
                    newNode->next = *poly;
                    *poly = newNode;
                } else {
                    newNode->next = prev->next;
                    prev->next = newNode;
                }
            }

            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
}

int main() {
    printf("Enter polynomial 1:\n");
    createExp(&poly1);
    printf("Enter polynomial 2:\n");
    createExp(&poly2);

    printf("Polynomial 1 is: ");
    displayExp(poly1);
    printf("\n");

    printf("Polynomial 2 is: ");
    displayExp(poly2);
    printf("\n");

    struct polynomial *sum = NULL, *product = NULL;
    polyadd(poly1, poly2, &sum);
    polymultiply(poly1, poly2, &product);

    printf("Addtion: ");
    displayExp(sum);
    printf("\n");

    printf("Multiplication: ");
    displayExp(product);
    printf("\n");

    return 0;
}
