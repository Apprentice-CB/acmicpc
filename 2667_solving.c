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
    curNode->next = que->first;
    output.x = curNode->x;
    output.y = curNode->y;
    output.next = curNode->next;
    free(curNode);
    return output;
}

char map[25][25] = {0, };
bool visited[25][25] = {false, };
int size[25] = {0, };

int BFS(char** map, int N, int start_x, int start_y)
{
    queue que;
    initQueue(&que);
    int size = 1;
    enqueue(&que, start_x, start_y);
    int x = 0;
    int y = 0;
    node temp;
    while(queue.first != NULL)
    {
        temp = dequeue(&que);
        x = temp.x;
        y = temp.y;
        if (visited[x][y] == false && map[x][y] == '1')
        {
            size++;
            enqueue(&que, x, y);
        }
    }
}

int main(void)
{
    int N = 0;
    scanf("%d", &N);
    char** map;
    char** visited;
    map = (char**)malloc(sizeof(char*) * N);
    visited = (char**)malloc(sizeof(char*) * N);
    for (int i = 0; i < N; i++)
    {
        map[i] = (char*)malloc(sizeof(char) * N);
        visited[i] = (char*)malloc(sizeof(char) * N);
        scanf("%s", map[i]);
    }
    
    int cnt = 0;
    for (int xidx = 0; xidx < N; xidx++)
    {
        for (int yidx = 0; yidx < N; yidx++)
        {
            if (visited[xidx][yidx] == 0 && map[xidx][yidx] == '1')
            {
                
            }
        }
    }

}