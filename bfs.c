#include<stdio.h>
#define max 100

int main()
{
    int count, i, j, k = 0, start, queue[max], front = -1, rear = -1, value;

    printf("Enter the number of nodes to be created: ");
    scanf("%d", &count);

    if (count > max) 
    {
        printf("Error: Number of nodes exceeds the maximum allowed limit of %d.\n", max);
        return 1;
    }

    int num[count][count], output[100];
    int visited[count];  // To track visited nodes

    printf("Enter the values for adjacency matrix (0 and 1): \n");
    for(i = 0; i < count; i++)
    {
        for(j = 0; j < count; j++)
        {
            scanf("%d", &num[i][j]);
            if(num[i][j] != 0 && num[i][j] != 1)
            {
                printf("Invalid input. Adjacency matrix should only contain 0 or 1.\n");
                return 1;
            }
        }
    }

    printf("From where do you want to start the traversal (1 - %d): ", count);
    scanf("%d", &start);

    if (start < 1 || start > count) 
    {
        printf("Invalid starting node! It should be between 1 and %d.\n", count);
        return 1;
    }

    start--;
    for (i = 0; i < count; i++) visited[i] = 0;  // Mark all nodes as unvisited

    rear++;
    queue[rear] = start;
    visited[start] = 1;  // Mark the starting node as visited

    while (front < rear) 
    {
        value = queue[++front];
        output[k++] = value + 1;

        for (i = 0; i < count; i++) 
        {
            if (num[value][i] == 1 && !visited[i])  // If not visited
            {
                queue[++rear] = i;
                visited[i] = 1;  // Mark the node as visited
            }
        }  
    }

    printf("BFS Order: ");
    for (i = 0; i < k; i++) 
    {
        printf("%d ", output[i]);
    }
    printf("\n");

    return 0;
}


