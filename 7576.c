#include <stdio.h>

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
    

}