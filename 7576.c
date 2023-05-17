#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

void BFS(int** map, int N, int M)
{
    queue que;
    initQueue(&que);
    for (int nidx = 0; nidx < N; nidx++)
    {
        for (int midx = 0; midx < M; midx++)
        {
            if (map[nidx][midx] == 1)
            {
                enqueue(&que, nidx, midx);
                //printf("enqueue %d %d\n", nidx, midx);
            }
        }
    }

    int n_next = 0;
    int m_next = 0;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    node temp;
    while(que.first != NULL)
    {
        temp = dequeue(&que);
        for (int i = 0; i < 4; i++)
        {
            n_next = temp.x + dx[i];
            m_next = temp.y + dy[i];
            if (0 <= n_next && n_next < N && 0 <= m_next && m_next < M)
            {
                if (map[n_next][m_next] == 0)
                {
                    enqueue(&que, n_next, m_next);
                    //printf("enqueue %d %d\n", n_next, m_next);
                    map[n_next][m_next] = map[temp.x][temp.y] + 1;
                }
            }
        }
        
    }
    //printf("%d %d", n_next, m_next);
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

    int result = 0;
    BFS(map, N, M);

    for (int nidx = 0; nidx < N; nidx++)
    {
        for (int midx = 0; midx < M; midx++)
        {
            if (map[nidx][midx] == 0)
            {
                printf("-1");
                return 0;
            }
            else
            {
                if (map[nidx][midx] > result)
                {
                    result = map[nidx][midx];
                }
            }
        }
    }
    printf("%d", result-1);
}