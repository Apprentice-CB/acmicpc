#include <stdio.h>
#include <stdlib.h>

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
    node* newNode;
    newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
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

int dequeue(queue *que)
{
    node* tempNode;
    if (que->first == NULL)
    {
        return -1;
    }
    int data;
    tempNode = que->first;
    data = tempNode->data;
    que->first = tempNode->next;
    free(tempNode);
    return data;
}

node tree[100001];
node* treeAddr[100001];  // last address of tree linked list
int visited[100001];
int parent[100001];

void BFS(node* tree, int N, int R)
{
    queue que;
    initQueue(&que);
    enqueue(&que, R);
    visited[R] = 1;
    int v = 0;
    node* cur;
    while(que.first != NULL)
    {
        v = dequeue(&que);
        R = v;
        cur = &tree[v];
        cur = cur->next;
        while (cur != NULL)
        {
            v = cur->data;
            if (visited[v] == 0)
            {
                visited[v] = 1;
                parent[v] = R;
                enqueue(&que, v);
            }
            cur = cur->next;
        }
    }
}

int main(void)
{
    int N = 0;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
    {
        treeAddr[i] = &tree[i];
    }

    int u = 0;
    int v = 0;
    node* cur;
    for (int i = 1; i <= N-1; i++)
    {
        scanf("%d %d", &u, &v);
        cur = treeAddr[u];
        cur->next = (node*)malloc(sizeof(node));
        cur->next->data = v;
        cur->next->next = NULL;
        treeAddr[u] = cur->next;

        cur = treeAddr[v];
        cur->next = (node*)malloc(sizeof(node));
        cur->next->data = u;
        cur->next->next = NULL;
        treeAddr[v] = cur->next;
    }

    BFS(tree, N, 1);

    for (int i = 2; i <= N; i++)
    {
        printf("%d\n", parent[i]);
    }

}