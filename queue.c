#include <stdio.h>
int main() 
{
    int count, i, choice, front = -1, rear = -1, element;
    printf("Enter max size of queue: ");
    scanf("%d", &count);
    int num[count];
    while (1)
    {
        printf("\n1. Insert\n2. Delete\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 1)    // INSERT
        {
            if (rear == count - 1)
            {
                printf("Overflow\n");
            }
            else
            {
                printf("Enter element: ");
                scanf("%d", &element);
                if (front == -1) 
                    front = 0;
                num[++rear] = element;
            }
        }
        else if (choice == 2)   // DELETE
        {
            if (front == -1 || front > rear)
            {
                printf("Underflow\n");
            }
            else
            {
                printf("Deleted: %d\n", num[front++]);
                if (front > rear)
                    front = rear = -1;
            }
        }
        else if (choice == 3)
        {
            break;
        }
        else
        {
            printf("Invalid choice\n");
        }
        if (front != -1)
        {
            printf("Queue: ");
            for (i = front; i <= rear; i++)
                printf("%d ", num[i]);
            printf("\n");
        }
        else
        {
            printf("Queue is empty\n");
        }
    }
    return 0;
}
