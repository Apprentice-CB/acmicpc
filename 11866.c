#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    int value;
    struct node* next;
} node; 

typedef struct circularQueue
{
    struct node* start;
    struct node* last;
    int count;
} circularQueue;

void init(circularQueue* cqueue)
{
    cqueue->start = NULL;
    cqueue->last = NULL;
    cqueue->count = 0;
}

void push(circularQueue* cqueue, int N)
{
    node* tempNode = (node*)malloc(sizeof(node));
    tempNode->value = N;
    if (cqueue->start == NULL)
    {
        cqueue->start = tempNode;
    }
    else
    {
        cqueue->last->next = tempNode;
    }
    cqueue->last = tempNode;
    tempNode->next = NULL;
    cqueue->count++;
}

void makeCircular(circularQueue* cqueue)
{
    cqueue->last->next = cqueue->start;
}

int pop(circularQueue* cqueue, int K)
{
    node* currentNode = cqueue->last;
    for (int i = 0; i < K-1; i++)
    {
        currentNode = currentNode->next;
    }
    cqueue->last = currentNode;
    currentNode = currentNode->next;
    int returnValue = currentNode->value;
    cqueue->start = currentNode->next;
    cqueue->last->next = cqueue->start;
    free(currentNode);
    return returnValue;
}

int main()
{
    int N = 0;
    int K = 0;
    circularQueue* cqueue = (circularQueue*)malloc(sizeof(circularQueue));
    init(cqueue);
    scanf("%d %d", &N, &K);
    for (int i = 1; i <= N; i++) 
    {
        push(cqueue, i);
    }
    makeCircular(cqueue);
    printf("<");
    for (int i = 0; i < N-1; i++)
    {
        printf("%d, ", pop(cqueue, K));
    }
    printf("%d>", pop(cqueue, K));
    return 0;
}