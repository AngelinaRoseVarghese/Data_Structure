#include<stdio.h>
#include<stdlib.h>
struct node
{
	char url[1000];
	struct node *next;
	struct node *previous;
};
struct node *current, *head, *newnode;
int main()
{
	int option;
	printf("What do you want to do: \n 1. Visit new page \n 2.Go back \n 3.Go forward\n 4.Display current page\n 5.Exit\n");
	scanf("%d",&option);
	while(option!=5)
	{
		if(option==1)
		{
			newnode=(struct node*)malloc(sizeof(struct node));
			printf("Enter the URL: ");
			scanf("%s",newnode->url);
			newnode->previous=current;
			if(current!=NULL)
			{
				current->next=newnode;
			}
			newnode->next=NULL;
			current=newnode;
			
		}
		if(option==2)
		{
			if(current==NULL || current->previous==NULL)
			{
				printf("Cannot go back\n");
			}
			else
			{
				current=current->previous;
				printf("Previous visited site: %s\n",current->url);
			}
		}
		if(option==3)
		{
			if(current==NULL || current->next==NULL)
			{
				printf("Cannot go forward\n");
			}
			else
			{
				current=current->next;
				printf("Next visited site: %s\n",current->url);
			}
		}
		if(option==4)
		{
			if(current==NULL)
			{
				printf("No page visited yet\n");
			}
			else
			{
				printf("The current site: %s\n",current->url);
			}
		}
		printf("What do you want to do: \n 1. Visit new page \n 2.Go back \n 3.Go forward\n 4.Display current page\n 5.Exit\n");
		scanf("%d",&option);
	}
	return 0;
}
