#include <stdio.h>
#include <stdlib.h>

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
    node* cur;
    node result;
    cur = que->first;
    que->first = cur->next;
    result.x = cur->x;
    result.y = cur->y;
    result.next = cur->next;
    free(cur);
    return result;
}

int map[101][101] = {0, };
int visited[101][101] = {0, };
int route[101][101] = {0, };
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void BFS(int map[][101], int N, int M)
{
    queue q;
    initQueue(&q);
    visited[0][0] = 1;
    route[0][0] = 1;
    enqueue(&q, 0, 0);
    int x = 0;
    int y = 0;
    node cur;
    int path = 0;
    while(q.first != NULL)
    {
        cur = dequeue(&q);
        for (int i = 0; i < 4; i++)
        {
            x = cur.x + dx[i];
            y = cur.y + dy[i];
            if (0 <= x && x < N && 0 <= y && y < M) 
            {
                if (visited[x][y] == 0 && map[x][y] == 1)
                {
                    visited[x][y] = 1;
                    route[x][y] = route[cur.x][cur.y] + 1;
                    enqueue(&q, x, y);
                }
            }
        }
    }

}


int main(void)
{
    int N = 0; // stands for y
    int M = 0; // stands for x
    scanf("%d %d", &N, &M);

    for (int nidx = 0; nidx < N; nidx++)
    {
        for (int midx = 0; midx < M; midx++)
        {
            scanf("%1d", &map[nidx][midx]);
        }
    }   
    BFS(map, N, M);
    printf("%d", route[N-1][M-1]);

}