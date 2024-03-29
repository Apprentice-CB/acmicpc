#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int visited_order[100001] = {0, };
int visited[100001] = {0, };

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

node graph[100001];

void initQueue(queue* q)
{
    q->first = NULL;
    q->last = NULL;
}

void enqueue(queue* q, int data)
{
    node* temp;
    temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    if (q->first == NULL)
    {
        q->first = temp;
        q->last = temp;
    }
    else
    {
        q->last->next = temp;
        q->last = temp;
    }
}

int isEmpty(queue* q)
{
    if (q->first == NULL)
    {
        return 1;
    }
    return 0;
}

int dequeue(queue* q)
{
    node* temp;
    temp = q->first;
    int data = temp->data;
    q->first = temp->next;
    free(temp);

    return data;
}

void pushGraph(node* graphNode, int a)
{
    node* cur;
    cur = graphNode;
    
    node* temp = (node*)malloc(sizeof(node));
    temp->data = a;
    temp->next = NULL;
    
    node* next_cur;
    int data = 0;
    int next_data = 0;
    // add node while searching
    while (cur->next != NULL)
    {
        data = cur->data;
        next_data = cur->next->data;
        if (a > data && next_data > a)
        {
            temp->next = cur->next;
            cur->next = temp;
            return;
        }
        cur = cur->next;
    }
    cur->next = temp;
}

void sortGraph(node* graphNode)
{
    int length = -1;
    int temp;
    node* cur;
    cur = graphNode;
    
    while(cur != NULL)
    {
        cur = cur->next;
        length++;
    }
    cur = graphNode;
    for (int i = 0; i < length; i++)
    {
        if (cur->next == NULL)
        {       
            break;
        }
        for (int j  = 0; j < length-1; j++) 
        {
            if (cur->data > cur->next->data)
            {
                temp = cur->data;
                cur->data = cur->next->data;
                cur->next->data = temp;
            }
            cur = cur->next;
        }
        cur = graphNode->next;
    }
}


void bfs(node graph[100001], int N, int R)
{
    queue que;
    initQueue(&que);
    int cnt = 1;
    visited[R] = 1;
    visited_order[R] = cnt;
    cnt++;
    enqueue(&que, R);
    int v = 0;
    node* cur;
    while(!isEmpty(&que))
    {
        cur = &graph[dequeue(&que)];
        cur = cur->next;
        while (cur != NULL)
        {
            v = cur->data;
            if (visited[v] == 0)    // If not visited
            {
                visited[v] = 1; // Then visit
                visited_order[v] = cnt;
                cnt++;
                enqueue(&que, v);
            }
            cur = cur->next;
        }
    }

    for (int i = 1; i <= N; i++)
    {
        printf("%d\n", visited_order[i]);
    }
}

int main(void)
{
    int N = 0;
    int M = 0;
    int R = 0;
    scanf("%d %d %d", &N, &M, &R);

    int col = 0;
    int row = 0;
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &row, &col);
        pushGraph(&graph[row], col);
        pushGraph(&graph[col], row);
    }

    bfs(graph, N, R);

    return 0;
}