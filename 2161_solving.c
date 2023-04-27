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
} queue

void initQueue(queue* que)
{
    que->first = NULL;
    que->last = NULL;
}

void enQueue(queue* que, int data)
{
    node* temp;
    
}

int main(void)
{

}