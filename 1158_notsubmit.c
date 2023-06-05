#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int num;
    struct node* next;
} node;

typedef struct cqueue
{
    struct node* first;
    struct node* last;
} cqueue;

void enqueue(cqueue* cq, int num)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->num = num;
    if (cq->first == NULL)
    {
        cq->first = newNode;
        cq->last = newNode;
    }
    else
    {
        cq->last->next = newNode;
        cq->last = newNode;
    }
    newNode->next = cq->first;
}

int dequeue(cqueue* cq, int cnt)
{
    if (cq->first == NULL)
    {
        return -1;
    }
    node* temp = cq->last;
    node* prev;
    for (int i = 0; i < cnt; i++)
    {
        prev = temp;
        temp = prev->next;
    }
    int v = temp->num;
    cq->first = temp->next;
    cq->last = prev;
    cq->last->next = cq->first;
    free(temp);
    return v;
}

int main(void)
{
    int N = 0;
    int K = 0;
    scanf("%d %d", &N, &K);
    cqueue* cq = (cqueue*)malloc(sizeof(cqueue));
    cq->first = NULL;
    cq->last = NULL;
    
    for (int i = 1; i <= N; i++)
    {
        enqueue(cq, i);
    }

    int* arr = (int*)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
    {
        arr[i] = dequeue(cq, K);
    }

    printf("<");
    for (int i = 0; i < N-1; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("%d>", arr[N-1]);
}