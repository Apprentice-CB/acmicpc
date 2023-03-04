#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
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

void push(queue* que, int val)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->value = val;
    if (que->first == NULL)
    {
        que->first = temp;
    }
    else
    {
        que->last->next = temp;
    }
    que->last = temp;
}

/* No need to return */
void pop(queue* que)
{
    node* tempNode = que->first;
    que->first = tempNode->next;
    free(tempNode);

    que->last->next = que->first;
    que->last = que->first;
    que->first = que->last->next;
    que->last->next = NULL;
}

int main()
{
    int N = 0;
    scanf("%d", &N);
    queue* que = (queue*)malloc(sizeof(queue));
    initQueue(que);
    for (int i = 1; i <= N; i++) 
    {
        push(que, i);
    }
    for (int i = 0; i < N-1; i++)
    {
        pop(que);
    }
    printf("%d", que->first->value);
    return 0;
}