#include <stdio.h>
#define MAX 100
int main()
{
    int nodes, i, j, startNode;
    int adj[MAX][MAX], queue[MAX], visited[MAX] = {0};
    int front = 0, rear = -1;
    printf("Enter number of nodes: ");
    scanf("%d", &nodes);
    printf("Enter adjacency matrix:\n");
    for (i = 0; i < nodes; i++)
    {
        for (j = 0; j < nodes; j++)
            {
                scanf("%d", &adj[i][j]);
            }
    }
    printf("Enter starting node (1 - %d): ", nodes);
    scanf("%d", &startNode);
    startNode--;  // convert to 0-based index
    queue[++rear] = startNode;
    visited[startNode] = 1;
    printf("BFS Traversal Order: ");
    while (front <= rear)
    {
        int current = queue[front++];
        printf("%d ", current + 1);
        for (i = 0; i < nodes; i++) 
        {
            if (adj[current][i] == 1 && !visited[i])
            {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
    return 0;
}
