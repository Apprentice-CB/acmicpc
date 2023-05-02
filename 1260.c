#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

uint8_t graph[1001][1001] = {0, };
uint8_t visited[1001] = {0, };

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

void initQueue(queue* que)
{
    que->first = NULL;
    que->last = NULL;
}

void enqueue(queue* que, int data)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    if (que->first == NULL)
    {
        que->first = temp;
        que->last = temp;
    }
    else
    {
        que->last->next = temp;
        que->last = temp;
    }
}

int dequeue(queue* que)
{
    node* temp;
    if (que->first == NULL)
    {
        return -1;
    }
    temp = que->first;
    int data = temp->data;
    que->first = temp->next;
    free(temp);
    return data;
}

int isEmpty(queue* que)
{
    if (que->first == NULL)
    {
        return 1;
    }
    return 0;
}


int compare(const void* a, const void* b)
{
    int x = *(int*) a;
    int y = *(int*) b;
    return x > y;
}

void BFS(uint8_t graph[][1001], int N, int R)
{
    queue q;
    initQueue(&q);

    int* visited = (int*)malloc(sizeof(int) * (N+1));
    memset(visited, 0, sizeof(int) * (N+1));

    enqueue(&q, R);
    printf("%d ", R);
    visited[R] = 1;
    int u = 0;
    int v = 0;
    while(!isEmpty(&q))
    {
        u = dequeue(&q);
        for (int i = 1; i <= N; i++)
        {
            if (visited[i] == 0 && graph[u][i] == 1)
            {
                enqueue(&q, i);
                visited[i] = 1;
                printf("%d ", i);
            }
        }
    }
    free(visited);
}

void DFS(uint8_t graph[][1001], int N, int R)
{
    visited[R] = 1;
    printf("%d ", R);
    for (int i = 1; i <= N; i++)
    {
        if (visited[i] == 0 && graph[R][i] == 1)
        {
            DFS(graph, N, i);
        }
    }
}

int main(void)
{
    int N = 0;
    int M = 0;
    int R = 0;
    scanf("%d %d %d", &N, &M, &R);
    int x = 0;
    int y = 0;
    for (int i = 0; i < M; i++)
    {
        scanf(" %d %d", &x, &y);
        graph[x][y] = 1;
        graph[y][x] = 1;
    }

    DFS(graph, N, R);
    printf("\n");
    BFS(graph, N, R);
}