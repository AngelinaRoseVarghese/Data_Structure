#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_SIZE 100
struct tree
{
	char data;
	struct tree *left;
	struct tree *right;
};

int main() 
{
    int count, i, j = 0, top = -1;
    char expression[MAX_SIZE], stack[MAX_SIZE], postfix[MAX_SIZE];
   
    printf("How many symbols would you wish to enter: ");
    scanf("%d", &count);
    if(count > MAX_SIZE) 
    {
        printf("Input size exceeds maximum allowed size of %d\n", MAX_SIZE);
        return 1;
    }
    printf("Enter the expression from left to right: ");
    scanf("%s", expression);
    for(i = 0; expression[i] != '\0'; i++) 
    {
        if(isalpha(expression[i])) 
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
            while(top != -1 && 
                  ((stack[top] == '*' || stack[top] == '/') || 
                   (expression[i] == '+' || expression[i] == '-') && 
                   (stack[top] == '+' || stack[top] == '-'))) 
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
    struct tree *newnode, *newnode1, *newnode2;
    struct tree *stack2[2000];
    int top2=-1;
    for(i = 0; postfix[i] != '\0'; i++) 
    {
    	if(isdigit(postfix[i]) || isalpha(postfix[i]))
    	{
    		newnode=(struct tree*)malloc(sizeof(struct tree));
    		newnode->data=postfix[i];
    		newnode->left=newnode->right=NULL;
		if (top2 < 1999)
		{
			stack2[++top2] = newnode; 
		}
    	}
    	else
    	{
    		newnode=(struct tree*)malloc(sizeof(struct tree));
    		newnode1=stack2[top2--];
    		newnode2=stack2[top2--];
    		newnode->data = postfix[i]; 
    		newnode->left=newnode1;
    		newnode->right=newnode2;
    		stack2[++top2] = newnode;
    	}
    }
    struct tree *root=stack2[top2];
    printf("The root of the postfix is %c\n",root->data);
    return 0;
}

