#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int weight;
    struct node* next;
} node;

typedef struct queue
{
    struct node* first;
    struct node* last;
    int total_weight;
    int length;
} queue;

void initQueue(queue* que)
{
    que->first = NULL;
    que->last = NULL;
    que->total_weight = 0;
    que->length = 0;
}

void enqueue(queue* que, int weight)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->weight = weight;
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

void next(queue* que)
{
    
}

void dequeue(queue* que)
{
    node* tempNode = que->first;
    if (tempNode == NULL)
    {
        return;
    }
    else
    {
        que->total_weight -= tempNode->weight;
        que->first = tempNode->next;
        free(tempNode);
    }
}



int main(void)
{

}