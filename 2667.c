#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
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
    node output;
    node* curNode;
    // empty queue is not considered
    curNode = que->first;
    que->first = curNode->next;
    output.x = curNode->x;
    output.y = curNode->y;
    output.next = curNode->next;
    free(curNode);
    return output;
}

uint8_t map[26][26] = {0, };
bool visited[26][26] = {0, };

int BFS(uint8_t map[][26], int N, int start_x, int start_y)
{
    queue que;
    initQueue(&que);
    int size = 1;
    enqueue(&que, start_x, start_y);
    visited[start_x][start_y] = true;
    //printf("enqueue: x = %d, y = %d\n", start_x, start_y);
    int xidx = 0;
    int yidx = 0;
    node cur;
    while(que.first != NULL)
    {
        cur = dequeue(&que);
        //printf("dequeue: x = %d, y = %d\n", x, y);
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
            if (0 <= xidx && xidx < N && 0 <= yidx && yidx < N)
            {
                if (map[xidx][yidx] == 1 && visited[xidx][yidx] == 0)
                {
                    enqueue(&que, xidx, yidx);
                    visited[xidx][yidx] = true;
                    size++;
                    //printf("enqueue x: %d, y: %d, size=%d\n", xidx, yidx, size);
                }
            }
        }
    }
    //printf("BFS done, size: %d\n", size);
    return size;
}

int compare(const void* a, const void* b)
{
    return *(int*)a > *(int*)b;
}

int main(void)
{
    int N = 0;
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%1d", &map[i][j]);
        }
    }

    int cnt = 0;
    int size = 0;
    int arr[26*26] = {0, };
    for (int xidx = 0; xidx < N; xidx++)
    {
        for (int yidx = 0; yidx < N; yidx++)
        {
            if (visited[xidx][yidx] == 0 && map[xidx][yidx] == 1)
            {
                size = BFS(map, N, xidx, yidx);
                arr[cnt] = size;
                cnt++;
            }
        }
    }

    printf("%d\n", cnt);
    qsort(arr, cnt, sizeof(int), compare);
    for (int i = 0; i < cnt; i++)
    {
        printf("%d\n", arr[i]);
    }
}