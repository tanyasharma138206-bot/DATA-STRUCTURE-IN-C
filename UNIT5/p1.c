
#include <stdio.h>

#define MAX 20

int queue[MAX];
int front = -1, rear = -1;
int visited[MAX];

void enqueue(int vertex)
{
    if (rear == MAX - 1)
        return;

    if (front == -1)
        front = 0;

    queue[++rear] = vertex;
}

int dequeue()
{
    if (front == -1 || front > rear)
        return -1;

    return queue[front++];
}

void BFS(int graph[MAX][MAX], int n, int start)
{
    int i, vertex;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front <= rear)
    {
        vertex = dequeue();
        printf("%d ", vertex);

        for (i = 0; i < n; i++)
        {
            if (graph[vertex][i] == 1 && visited[i] == 0)
            {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int graph[MAX][MAX];
    int n, i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    BFS(graph, n, start);

    return 0;
}
