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

void initQueue(queue* que)
{
    que->first = NULL;
    que->last = NULL;
}

void enQueue(queue* que, int data)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    if (que->first == NULL)
    {
        que->first = temp;
        que->last = temp;
    }
    else
    {
        que->last->next = temp;
        que->last = temp;
    }
}

int deQueue(queue* que)
{
    if (que->first == NULL)
    {
        return -1;
    }
    node* temp;
    temp = que->first;
    int data = temp->data;
    que->first = temp->next;
    free(temp);
    return data;
}

int main(void)
{
    int N = 0;
    scanf("%d", &N);
    queue que;
    initQueue(&que);
    for (int i = 1; i <= N; i++)
    {
        enQueue(&que, i);
    }
    int temp = 0;
    for (int i = 1; i <= N; i++)
    {
        temp = deQueue(&que);
        printf("%d ", temp);
        temp = deQueue(&que);
        enQueue(&que, temp);
    }
}