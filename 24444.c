#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node* next;
} node;

typedef struct queue
{
    struct node* first;
    struct node* last;
} queue;

int graph[100001][100001];
queue que;
int visited[100001] = {0, };

void initQueue(queue* q)
{
    q->first = NULL;
    q->last = NULL;
}

void enqueue(queue* q, int data)
{
    node* temp;
    temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    if (q->first == NULL)
    {
        q->first = temp;
        q->last = temp;
        temp->next = q->last;
    }
    else
    {
        q->last->next = temp;
        q->last = temp;
    }
}

int isEmpty(queue* q)
{
    if (q->first == NULL)
    {
        return 1;
    }
    return 0;
}

int dequeue(queue* q)
{
    if (isEmpty(q))
    {
        return 100;
    }
    node* temp;
    temp = q->first;
    int data = temp->data;
    q->first = temp->next;
    free(temp);
    return data;
}

void bfs(int graph[][100001], int R, int N, int* visited, queue* q)
{
    int visited_order[N+1];
    memset(visited_order, 0, sizeof(int)*N);
    int cnt = 1;
    for (int v = 1; v <= N; v++)
    {
        if (v != R)
        {
            visited[v] = 0;
        }
        else
        {
            visited[v] = 1;
            visited_order[v] = cnt;
            cnt++;
        }
    }
    enqueue(q, R);
    int u = 0;
    while(!isEmpty(q))
    {
        u = dequeue(q);
        for (int v = 1; v <= N; v++)
        {
            if (graph[u][v] == 1)
            {
                if (visited[v] == 0)
                {
                    visited[v] = 1;
                    visited_order[v] = cnt;
                    cnt++;
                    enqueue(q, v);
                }
            }
        }
    }
    for (int i = 1; i <= N; i++)
    {
        printf("%d\n", visited_order[i]);
    }
}

int main(void)
{
    int N = 0;
    int M = 0;
    int R = 0;
    scanf("%d %d %d", &N, &M, &R);

    int col = 0;
    int row = 0;
    for (int i = 0; i < M; i++)
    {
        scanf(" %d %d", &row, &col);
        graph[row][col] = 1;
        graph[col][row] = 1;
    }
    initQueue(&que);
    
    bfs(graph, R, N, visited, &que);

}