#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL, *newnode, *temp,*prevnode,*nextnode;
int main()
{
	int choice,i=1,position,count=0;
	printf("What do you want to do:\n 1.Insertion at front\n 2.Insertion at end\n 3.Insertion at any other position\n 4.Deletion at front\n 5.Deletion at end\n 6.Deletion at any other position\n 7.Exit\n");
	scanf("%d",&choice);
	while(choice!=7)
	{
		if(choice==1)
		{
			newnode=(struct node*)malloc(sizeof(struct node));
			printf("Enter the number to insert at the beginning of the list: ");
			scanf("%d",&newnode->data);
			newnode->next=head;
			head=newnode;
			if(newnode==NULL)
			{
				printf("Insertion is not possible\n");
			}
			temp = head;
    			if (temp == NULL)
    			{
        			printf("List is empty.\n");
    			}
    			printf("List: ");
    			while (temp != NULL) 
    			{
        			printf("%d \t", temp->data);
        			temp = temp->next;
    			}
		}
		if(choice==2)
		{
			newnode=(struct node*)malloc(sizeof(struct node));
			printf("Enter the number to insert at the end of the list: ");
			scanf("%d",&newnode->data);
			newnode->next=0;
			temp=head;
			while(temp->next!=0)
			{
				temp=temp->next;
			}
			temp->next=newnode;
			temp = head;
    			if (temp == NULL)
    			{
        			printf("List is empty.\n");
    			}
    			printf("List: ");
    			while (temp != NULL) 
    			{
        			printf("%d \t ", temp->data);
        			temp = temp->next;
    			}
		}
		if (choice == 3) 
		{
    			int position, i;
    			struct node *temp;
    			newnode = (struct node*)malloc(sizeof(struct node));
    			if (newnode == NULL) 
    			{
        			printf("Memory allocation failed\n");
        			exit(1);
    			}
    			printf("Enter the number to insert: ");
    			scanf("%d", &newnode->data);
    			newnode->next = NULL;
    			printf("Enter the position where the data should be inserted: ");
    			scanf("%d", &position);
    			if (position < 1) 
    			{
        			printf("Invalid position\n");
    			} 
    			else if (position == 1) 
    			{
        			newnode->next = head;
        			head = newnode;
    			} 
    			else 
    			{
        			temp = head;
        			for (i = 1; i < position - 1 && temp != NULL; i++) 
        			{
            				temp = temp->next;
        			}
        			if (temp == NULL) 
        			{
            				printf("Invalid position\n");
        			} 
        			else 
        			{
            				newnode->next = temp->next;
            				temp->next = newnode;
        			}
    			}
    			temp = head;
    			if (temp == NULL)
    			{
        			printf("List is empty.\n");
    			}
    			printf("List: ");
    			while (temp != NULL) 
    			{
        			printf("%d \t", temp->data);
        			temp = temp->next;
    			}
		}
		if(choice==4)
		{
			temp=head;
			head=head->next;
			free(temp);
			temp = head;
    			if (temp == NULL)
    			{
        			printf("List is empty.\n");
    			}
    			printf("List: ");
    			while (temp != NULL) 
    			{
        			printf("%d \t ", temp->data);
        			temp = temp->next;
    			}
		}
		if(choice==5)
		{
			temp=head;
			while(temp->next!=0)
			{
				prevnode=temp;
				temp=temp->next;
			}
			if(temp==head)
			{
				head=0;
			}
			else
			{
				prevnode->next=0;
			}
			free(temp);
			temp = head;
    			if (temp == NULL)
    			{
        			printf("List is empty.\n");
    			}
    			printf("List: ");
    			while (temp != NULL) 
    			{
        			printf("%d \t ", temp->data);
        			temp = temp->next;
    			}
		}
		if(choice==6)
		{
			temp=head;
			printf("Enter the position to delete: ");
			scanf("%d", &position);
			while(i<position-1)
			{
				temp=temp->next;
				i++;
			}
			nextnode=temp->next;
			temp->next=nextnode->next;
			free(nextnode);
			temp = head;
    			if (temp == NULL)
    			{
        			printf("List is empty.\n");
    			}
    			printf("List: ");
    			while (temp != NULL) 
    			{
        			printf("%d \t", temp->data);
        			temp = temp->next;
    			}
		}
		printf("\n\nWhat do you want to do:\n 1.Insertion at front\n 2.Insertion at end\n 3.Insertion at any other position\n 4.Deletion at front\n 5.Deletion at end\n 6.Deletion at any other position\n 7.Exit\n");
		scanf("%d",&choice);
	}
	return 0;
}
	
