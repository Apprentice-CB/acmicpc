#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node* next;
    struct node* prev;
} node;

typedef struct cqueue
{
    node* head;
    node* tail;
} cqueue;

void init(cqueue* cq)
{
    cq->head = NULL;
    cq->tail = NULL;
}

void push(cqueue* cq, int data)
{
    node* new_node = (node*)malloc(sizeof(node));
    new_node
}

int pop(cqueue* cq)
{
    return 0;
}

void left(cqueue* cq)
{

}

void right(cqueue* cq)
{

}

int main(void)
{
    int N = 0;
    int M = 0;
    scanf("%d %d", &N, &M);
    cqueue* cque = (cqueue*)malloc(sizeof(cqueue));
    init(cque);
    for (int i = 1; i <= N; i++)
    {

    }

    return 0;
}