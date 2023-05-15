#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int x;
    int y;
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

void enqueue(queue* que, int x, int y)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;
    if (que->first == NULL)
    {
        que->first = newNode;
        que->last = newNode;
    }
    else
    {
        que->last->next = newNode;
        que->last = newNode;
    }
}

node dequeue(queue* que)
{
    node* temp;
    node output;
    temp = que->first;
    output.x = temp->x;
    output.y = temp->y;
    que->first = temp->next;
    free(temp);
    return output;
}

void BFS(int** map, int N, int M, int nidx, int midx)
{
    queue que;
    initQueue(&que);
    int** visited = (int**)malloc(sizeof(int*) * N);
    for (int i = 0; i < N; i++)
    {
        visited[i] = (int*)malloc(sizeof(int) * M);
        memset(visited[i], 0, sizeof(int) * M);
    }
    visited[nidx][midx] = 0;
    enqueue(&que, nidx, midx);
    int n_next = 0;
    int m_next = 0;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    node cur;
    while (que.first != NULL)
    {
        cur = dequeue(&que);
        for (int i = 0; i < 4; i++)
        {
            n_next = cur.x + dx[i];
            m_next = cur.y + dy[i];
            if (visited[n_next][m_next] == 0 && map[n_next][m_next] == 0)
            {
                enqueue(&que, n_next, m_next);
                visited[n_next][m_next] = 1;
            }
        }
    }
}

int main(void)
{
    int N = 0;
    int M = 0;
    scanf("%d %d", &M, &N);
    int** map = (int**)malloc(sizeof(int*) * N);
    for (int i = 0; i < N; i++)
    {
        map[i] = (int*)malloc(sizeof(int) * M);
    }

    for (int nidx = 0; nidx < N; nidx++)
    {
        for (int midx = 0; midx < M; midx++)
        {
            scanf(" %d", &map[nidx][midx]);
        }
    }

    int** map_cpy = (int**)malloc(sizeof(int*) * N);
    for (int i = 0; i < N; i++)
    {
        map_cpy[i] = (int*)malloc(sizeof(int) * M);
        memcpy(map_cpy[i], map[i], sizeof(int) * M);
    }

    for (int nidx = 0; nidx < N; nidx++)
    {
        for (int midx = 0; midx < M; midx++)
        {
            if (map_cpy[nidx][midx] == 1)
            {
                BFS(map, N, M, nidx, midx);
            }
        }
    }

    for (int nidx = 0; nidx < N; nidx++)
    {
        for (int m)
    }
}