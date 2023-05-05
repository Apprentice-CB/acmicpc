#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
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

void initQueue(queue *que)
{
    que->first = NULL;
    que->last = NULL;
}

void enqueue(queue *que, int x, int y)
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
    
    temp = que->first;
    que->first = temp->next;
    node output;
    output.x = temp->x;
    output.y = temp->y;
    output.next = NULL;
    free(temp);
    return output;
}

bool visited[100][100] = {false, };

int BFS(bool** map, int N, int M, int start_x, int start_y)
{
    queue que;
    initQueue(&que);
    visited[start_x][start_y] = true;
    enqueue(&que, start_x, start_y);
    //printf("enqueue x: %d, y: %d\n", start_x, start_y);
    int size = 1;
    node cur;
    int xidx = 0;
    int yidx = 0;
    while(que.first != NULL)
    {
        cur = dequeue(&que);
        //printf("dequeue x: %d, y: %d\n", cur.x, cur.y);
        for (int i = 0; i < 4; i++)
        {
            if (i == 0)
            {
                xidx = cur.x;
                yidx = cur.y-1;
            }
            else if (i == 1)
            {
                xidx = cur.x;
                yidx = cur.y+1;
            }
            else if (i == 2)
            {
                xidx = cur.x-1;
                yidx = cur.y;
            }
            else if (i == 3)
            {
                xidx = cur.x+1;
                yidx = cur.y;
            }
            if (0 <= xidx && xidx < N && 0 <= yidx && yidx < M)
            {
                if (map[xidx][yidx] == true && visited[xidx][yidx] == false)
                {
                    enqueue(&que, xidx, yidx);
                    visited[xidx][yidx] = true;
                    size++;
                    //printf("enqueue x: %d, y: %d, size=%d\n", xidx, yidx, size);
                }
            }
        }
    }
    //printf("return size: %d\n", size);
    return size;
}

int compare(const void* a, const void* b)
{
    return *(int*)a > *(int*)b;
}

int main(void)
{
    int M = 0; // stands for y
    int N = 0; // stands for x
    int K = 0;
    scanf("%d %d %d", &M, &N, &K);

    bool** map = (bool**)malloc(sizeof(bool*) * N); // stands for x
    for (int i = 0; i < N; i++)
    {
        map[i] = (bool*)malloc(sizeof(bool) * M); // stands for y
        memset(map[i], true, sizeof(bool) * M);
    }

    int x_min = 0;
    int x_max = 0;
    int y_min = 0;
    int y_max = 0;
    for (int i = 0; i < K; i++)
    {
        scanf("%d %d %d %d", &x_min, &y_min, &x_max, &y_max);
        for (int xidx = x_min; xidx < x_max; xidx++)
        {
            for (int yidx = y_min; yidx < y_max; yidx++)
            {
                map[xidx][yidx] = false;
                visited[xidx][yidx] = true;
            }
        }
    }
    /*
    for (int xidx = 0; xidx < N; xidx++)
    {
        for (int yidx = 0; yidx < M; yidx++)
        {
            printf("%d ", map[xidx][yidx]);
        }
        printf("\n");
    }
    */
    
    int cnt = 0;
    int arr[100] = {0, };
    for (int xidx = 0; xidx < N; xidx++)
    {
        for (int yidx = 0; yidx < M; yidx++)
        {
            if (map[xidx][yidx] == true && visited[xidx][yidx] == false)
            {
                arr[cnt] = BFS(map, N, M, xidx, yidx);
                cnt++;
            }
        }
    }

    printf("%d\n", cnt);
    qsort(arr, cnt, sizeof(int), compare);
    for (int i = 0; i < cnt; i++)
    {
        printf("%d ", arr[i]);
    }
}