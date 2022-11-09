#include <stdio.h>
#include <stdlib.h>
int visit[100];
int visited[100];
struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};
int isEmpty(struct queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}
int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("This Queue is full\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}

int dequeue(struct queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("This Queue is empty\n");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}
void DFS(int n, int G[n][n], int d, int i)
{
    int j;
    printf("%d->", i);
    visited[i] = 1;
    for (j = 0; j < n; j++)
    {
        if (d == 0)
            return;
        if (visit[j] != 1 && G[i][j] == 1)
            DFS(n, G, d - 1, j);
    }
}
void BFS(int n, int G[n][n], int i, struct queue q, int k)
{
    int j;
    printf("%d->", i);
    visit[i] = 1;
    enqueue(&q, i);
    while (!isEmpty(&q))
    {
        int node = dequeue(&q), count = 0;
        for (int j = 0; j < n; j++)
        {
            if (G[node][j] == 1 && visit[j] != 1)
            {
                printf("%d->", j);
                visit[j] = 1;
                enqueue(&q, j);
                count++;
            }
            if (count == k)
                break;
        }
    }
    return;
}
int main()
{
    int i, j, n, m, v1, v2, s, k;
    struct queue q;
    q.size = 100;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));
    printf("Enter the number of nodes 'n' in the graph: ");
    scanf("%d", &n);
    int g[n][n];
    printf("\nEnter the graph:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &g[i][j]);
        }
    }
    printf("\nEnter the starting index: ");
    scanf("%d", &s);
    printf("\nResults:");
    for (int w = 0; w < 4; w++)
    {
        for (i = 0; i < n; i++)
            visit[i] = 0;
        printf("\nThe Beam-width is %d\t", w);
        BFS(n, g, s, q, w);
    }
}
