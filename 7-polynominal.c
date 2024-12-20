#include <stdio.h>
#include <stdlib.h>


typedef struct Poly Poly;

struct Poly{
    int power;
    int coeff;
    Poly *next;
};


Poly *CreateNode(int power,int coeff) {
  Poly *newNode = (Poly *)malloc(sizeof(Poly));
  if (newNode == NULL) {
    printf("\nError Creating Node!");
  }
  newNode->power = power;
  newNode->coeff = coeff;
  newNode->next = NULL;
  return newNode;
}


Poly *AddPolynomial(Poly *Exp1,Poly *Exp2){
    Poly **PolySum;
    (*PolySum) = CreateNode(0,0);
    int i,j;
    if(Exp1->power>Exp2->power){
        (*PolySum) = Exp1;
        Exp1 = Exp1->next; 
    } else if (Exp2->power>Exp1->power) {
        (*PolySum) = Exp2;
        Exp2 = Exp2->next;
    }
    else if (Exp1->power == Exp2->power) {
        
    }

    return (*PolySum);
}




int main(){

}