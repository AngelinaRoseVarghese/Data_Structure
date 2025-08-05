#include<stdio.h>
int main()
{
    int size, preferences, front = -1, rear = -1, element;
    printf("Enter the maximum size for the double ended queue: ");
    scanf("%d", &size);
    int num[size];
    printf("What do you want to do \n 1.Input from front \n 2.Input from rear \n 3.Delete from front \n 4.Delete from rear \n 5.Exit \n");
    scanf("%d", &preferences);
    while (preferences != 5)
    {
        if (preferences == 1)
        {
            if ((front == 0 && rear == size - 1) || (front == rear + 1))
            {
                printf("Overflow\n");
            }
            else
            {
                printf("Enter the element to be added: ");
                scanf("%d", &element);
                if (front == -1)
                {
                    front = rear = 0;
                }
                else if (front == 0)
                {
                    front = size - 1;
                }
                else
                {
                    front = front - 1;
                }
                num[front] = element;
                printf("\n");
            }
        }
        else if (preferences == 2)
        {
            if ((front == 0 && rear == size - 1) || (front == rear + 1))
            {
                printf("Overflow\n");
            }
            else
            {
                printf("Enter the element to be added: ");
                scanf("%d", &element);
                if (front == -1)
                {
                    front = rear = 0;
                }
                else if (rear == size - 1)
                {
                    rear = 0;
                }
                else
                {
                    rear = rear + 1;
                }
                num[rear] = element;
            }
        }
        else if (preferences == 3)
        {
            if (front == -1)
            {
                printf("Underflow\n");
            }
            else
            {
                int temp = num[front];
                printf("Deleted element is %d\n", temp);
                if (front == rear)
                {
                    front = rear = -1;
                }
                else if (front == size - 1)
                {
                    front = 0;
                }
                else
                {
                    front = front + 1;
                }
            }
        }
        else if (preferences == 4)
        {
            if (front == -1)
            {
                printf("Underflow\n");
            }
            else
            {
                int temp = num[rear];
                printf("Deleted element is %d\n", temp);
                if (front == rear)
                {
                    front = rear = -1;
                }
                else if (rear == 0)
                {
                    rear = size - 1;
                }
                else
                {
                    rear = rear - 1;
                }
            }
        }
        if (front != -1)
        {
            printf("The current elements in deque are: \n");
            int j = front;
            while (1)
            {
                printf("%d\t", num[j]);
                if (j == rear)
                    break;
                j = (j + 1) % size;
            }
            printf("\n");
            printf("\n");
        }
        else
        {
            printf("Deque is empty\n");
        }
        printf("What do you want to do \n 1.Input from front \n 2.Input from rear \n 3.Delete from front \n 4.Delete from rear \n 5.Exit \n");
        scanf("%d", &preferences);
    }
    return 0;
}
			
		
		
		
		
		
		
		
		
		
		
		
		
		
		
