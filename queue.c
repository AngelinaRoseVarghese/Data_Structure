#include<stdio.h>
int main()
{
	int count,i,preferences,front=-1,rear=-1,element=0;
	printf("Enter the maximun size for the for queue: ");
	scanf("%d",&count);
	int num[count];
	printf("What do you want: \n 1.Input element\n 2.Delete an element \n 3.Exit");
	scanf("%d",&preferences);
	while(preferences!=3)
	{
		if(preferences==1)
		{
			if(rear==count-1)
			{
				printf("Overflow\n");
			}
			else
			{
				printf("Enter the element to be added: ");
                		scanf("%d", &element);
				if(front == -1) front = 0; 
				rear++;
				num[rear] = element;
				printf("The elements in the queue are: \n");
				for(i = front; i <= rear; i++)
				{
				    printf("%d\t", num[i]);
				}
				printf("\n");
				
			}
		}
		else if(preferences==2)
		{
			if((rear<front)||(front==-1))
			{
				printf("Underflow\n");
			}
			else
			{
				element=0;
				element=num[front];
				printf("Deleted element is %d \n",element);
				front=front+1;
				if (front > rear)
				{ 
					front = -1;
					rear = -1;
				}
				if(front != -1) 
				{
					printf("The elements in the queue are: \n");
					for(i=front;i<=rear;i++)
					{
						printf("%d\t",num[i]);
					}
				}
			}
		}
		else if(preferences==3)
		break;
		else
		{
			printf("Invalid");
		}
		printf("\n What do you want: \n 1.Input element\n 2.Delete an element \n 3.Exit\n");
		scanf("%d",&preferences);
		printf("\n");
	}
	return 0;
}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
