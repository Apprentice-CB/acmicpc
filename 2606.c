#include <stdio.h>
#include <stdlib.h>

int network[101][101] = {0, };
int visited[101] = {0, };

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

void initQueue(queue *que)
{
    que->first = NULL;
    que->last = NULL;
}

void enqueue(queue *que, int data)
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

int dequeue(queue *que)
{
    node* temp = que->first;
    if (temp == NULL)
    {
        return -1;
    }
    int data = temp->data;
    que->first = temp->next;
    free(temp);
    return data;
}

int bfs(int network[][101], int N)
{
    int cnt = 0;
    queue que;
    initQueue(&que);
    enqueue(&que, 1);
    visited[1] = 1;
    int node_num = 0;
    while(que.first != NULL)
    {
        node_num = dequeue(&que);
        for (int i = 1; i <= N; i++)
        {
            if (network[node_num][i] == 1)
            {
                if (visited[i] == 0)
                {
                    enqueue(&que, i);
                    visited[i] = 1;
                    cnt++;
                }
            }
        }
    }

    return cnt;
}

int main(void)
{
    int N = 0;
    scanf("%d", &N);
    int E = 0;
    scanf("%d", &E);
    int r = 0;
    int c = 0;
    for (int i = 0; i < E; i++)
    {
        scanf("%d %d", &r, &c);
        network[r][c] = 1;
        network[c][r] = 1;
    }
    printf("%d", bfs(network, N));

}