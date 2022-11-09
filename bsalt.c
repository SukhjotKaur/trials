#include <stdio.h>
#include <stdlib.h>
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
int isFull(struct queue *q){
    if(q->r==q->size-1){
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
void BFS(int n, int G[n][n], int i)
{
    int visit[n];
    struct queue q;
    int j;
    q.size=100;
    // q.f = q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));
    printf("%d->", i);
    visit[i] = 1;
    enqueue(&q, i);
    while (!isEmpty(&q))
    {
        int node = dequeue(&q), count=0;
        for (int j = 0; j < n; j++)
        {
            if(count==2)
            break;
            if (G[node][j] == 1 && visit[j] != 1)
            {
                printf("%d->", j);
                visit[j] = 1;
                enqueue(&q, j);
                count++;
            }
            
        }
    }
    return;
}
int main()
{
    int i, j, n, m, v1, v2, s, option;
    printf("Enter the number of nodes 'n' in the graph: ");
    scanf("%d", &n);
    printf("Enter the number of edges 'm' in the graph: ");
    scanf("%d", &m);
    int g[n][n];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            g[i][j] = 0;
        }
    }
    for (i = 0; i < m; i++)
    {
        printf("Enter the vertices with edge in them: ");
        scanf("%d%d", &v1, &v2);
        g[v1-1][v2-1] = 1;
    }
    printf("\nEnter the starting index: ");
    scanf("%d", &s);
    printf("\nUsing Beam search: ");
    BFS(n, g, s);
}
