#include <stdio.h>

int main() 
{
    int element, front = -1, rear = -1, count, option;
    printf("How many numbers you want to enter: ");
    scanf("%d", &count);
    int num[count];

    printf("What do you want to do: \n 1.Insert an element\n 2.Delete an element\n 3.Exit\n");
    scanf("%d", &option);

    while(option != 3)
    {
        if(option == 1)
        {
            printf("Enter the element to be added: ");
            scanf("%d", &element);

            if((rear+1) % count == front)
            {
                printf("Queue is full\n");
            }
            else if(front == -1)
            {
                front = rear = 0;
                num[rear] = element;
            }
            else
            {
                rear = (rear+1) % count;
                num[rear] = element;
            }

            if(front != -1)
            {
                printf("Current queue: ");
                int i = front;
                while(1)
                {
                    printf("%d ", num[i]);
                    if(i == rear) break;
                    i = (i+1) % count;
                }
                printf("\n");
            }
        }

        else if(option == 2)
        {
            if(front == -1 && rear == -1)
            {
                printf("Queue is empty\n");
            }
            else if(front == rear)
            {
                printf("Deleted item is %d\n", num[front]);
                front = rear = -1;
                printf("Queue is empty now\n");
            }
            else
            {
                printf("Deleted item is %d\n", num[front]);
                front = (front+1) % count;
                printf("Current queue: ");
                int i = front;
                while(1)
                {
                    printf("%d ", num[i]);
                    if(i == rear) break;
                    i = (i+1) % count;
                }
                printf("\n");
            }
        }

        printf("What do you want to do: \n 1.Insert an element\n 2.Delete an element\n 3.Exit\n");
        scanf("%d", &option);
    }

    return 0;
}
