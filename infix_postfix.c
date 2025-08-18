#include <stdio.h>
#include <ctype.h>

int main() {
    int count, i, j = 0, top = -1;
    printf("How many symbols would you wish to enter: ");
    scanf("%d", &count);
    char expression[count], stack[count], postfix[count];
    printf("Enter the expression from left to right: ");
    scanf("%s", expression);
    
    for(i = 0; expression[i] != '\0'; i++) 
    {
        if(isdigit(expression[i]) || isalpha(expression[i])) 
        {
            postfix[j++] = expression[i];
        }
        else if(expression[i] == '(') 
        {
            stack[++top] = expression[i];
        }
        else if(expression[i] == ')') 
        {
            while(top != -1 && stack[top] != '(') 
            {
                postfix[j++] = stack[top--];
            }
            top--;
        }
        else 
        {
            while(top != -1 && ((stack[top] == '*' || stack[top] == '/') || (expression[i] == '+' || expression[i] == '-') &&  (stack[top] == '+' || stack[top] == '-'))) 
            {
                postfix[j++] = stack[top--];
            }
            stack[++top] = expression[i];
        }
    }

    while(top != -1) 
    {
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0';

    printf("\nResult: %s\n", postfix);
    return 0;
}

