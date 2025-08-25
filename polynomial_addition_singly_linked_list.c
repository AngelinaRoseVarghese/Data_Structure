#include<stdio.h>
#include <stdlib.h>
struct polynomial 
{
    int coeff;
    int expo;
    struct polynomial* next;
};
int main() 
{
    int count1, count2, i, temp;
    struct polynomial *polynomial1 = NULL, *polynomial2 = NULL, *result = NULL;
    struct polynomial *newNode, *tempPointer, *pointer1, *pointer2;

    printf("How many no.of terms you wish to enter in first polynomial: \n");
    scanf("%d", &count1);
    printf("Enter the details of first polynomial: \n");
    for(i = 0; i < count1; i++) 
    {
        newNode = (struct polynomial*)malloc(sizeof(struct polynomial));
        printf("Enter the coefficient and exponent: ");
        scanf("%d%d", &newNode->coeff,&newNode->expo);
        newNode->next = NULL;
        
        if (polynomial1 == NULL) 
        {
            polynomial1 = newNode;
        } 
        else 
        {
            tempPointer = polynomial1;
            while (tempPointer->next != NULL) 
            {
                tempPointer = tempPointer->next;
            }
            tempPointer->next = newNode;
        }
    }

    printf("How many no.of terms you wish to enter in second polynomial: \n");
    scanf("%d", &count2);
    printf("Enter the details of second polynomial: \n");
    for(i = 0; i < count2; i++) 
    {
        newNode = (struct polynomial*)malloc(sizeof(struct polynomial));
        printf("Enter the coefficient and exponent: ");
        scanf("%d%d", &newNode->coeff,&newNode->expo);
        newNode->next = NULL;
        
        if (polynomial2 == NULL) 
        {
            polynomial2 = newNode;
        } 
        else 
        {
            tempPointer = polynomial2;
            while (tempPointer->next != NULL) 
            {
                tempPointer = tempPointer->next;
            }
            tempPointer->next = newNode;
        }
    }

    pointer1 = polynomial1;
    pointer2 = polynomial2;

    while (pointer1 != NULL || pointer2 != NULL) 
    {
        newNode = (struct polynomial*)malloc(sizeof(struct polynomial));
        
        if (pointer1 == NULL)
         {
            newNode->coeff = pointer2->coeff;
            newNode->expo = pointer2->expo;
            pointer2 = pointer2->next;
        } 
        else if (pointer2 == NULL) 
        {
            newNode->coeff = pointer1->coeff;
            newNode->expo = pointer1->expo;
            pointer1 = pointer1->next;
        } 
        else if (pointer1->expo > pointer2->expo)
         {
            newNode->coeff = pointer1->coeff;
            newNode->expo = pointer1->expo;
            pointer1 = pointer1->next;
        } 
        else if (pointer2->expo > pointer1->expo)
         {
            newNode->coeff = pointer2->coeff;
            newNode->expo = pointer2->expo;
            pointer2 = pointer2->next;
        } 
        else 
        {
            newNode->coeff = pointer1->coeff + pointer2->coeff;
            newNode->expo = pointer1->expo;
            pointer1 = pointer1->next;
            pointer2 = pointer2->next;
        }

        newNode->next = NULL;
        
        if (result == NULL) 
        {
            result = newNode;
        } 
        else 
        {
            tempPointer = result;
            while (tempPointer->next != NULL) 
            {
                tempPointer = tempPointer->next;
            }
            tempPointer->next = newNode;
        }
    }

    printf("\nSum of Polynomials: ");
    tempPointer = result;
    while (tempPointer != NULL) 
    {
        printf("%dx^%d", tempPointer->coeff, tempPointer->expo);
        if (tempPointer->next != NULL) 
        {
            printf(" + ");
        }
        tempPointer = tempPointer->next;
    }
    printf("\n");
    
    return 0;
}
