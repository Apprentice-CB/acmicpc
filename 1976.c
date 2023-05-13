#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void enQueue(queue* que, int data)
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

int deQueue(queue* que)
{
    if (que->first == NULL)
    {
        return -1;
    }
    node* temp;
    temp = que->first;
    int data = temp->data;
    que->first = temp->next;
    free(temp);
    return data;
}

int map[201][201] = {0, };
int route[1001] = {0, };
int visited[201] = {0, };

void BFS(int N)
{
    queue q;
    initQueue(&q);
    visited[route[0]] = 1;
    enQueue(&q, route[0]);
    
    int v = 0;
    while(q.first != NULL)
    {
        v = deQueue(&q);
        for (int i = 1; i <= N; i++)
        {
            if (visited[i] == 0 && map[v][i] == 1)
            {
                enQueue(&q, i);
                visited[i] = 1;
            }
        }
    }
}

int main(void)
{
    int N = 0;
    int M = 0;
    scanf("%d", &N);
    scanf("%d", &M);
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            scanf(" %d", &map[i][j]);
        }
    }

    for (int i = 0; i < M; i++)
    {
        scanf(" %d", &route[i]);
    }

    BFS(N);

    for (int i = 0; i < M; i++)
    {
        if (visited[route[i]] == 1)
        {
            continue;
        }
        else
        {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
}