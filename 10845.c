#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node* next;
} node;

typedef struct queue
{
    struct node* first;
    struct node* last;
    int size;
} queue;

void init(queue* que)
{
    que->first = NULL;
    que->last = NULL;
    que->size = 0;
}

void push(queue *que, int data)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    que->size++;
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

int empty(queue* que)
{
    return que->first == NULL;
}

int pop(queue* que)
{
    node* tempNode;
    if (empty(que))
    {
        return -1;
    }
    tempNode = que->first;
    int data = tempNode->data;
    que->first = tempNode->next;
    que->size--;
    free(tempNode);
    return data;
}

int size(queue* que)
{
    return que->size;
}

int front(queue* que)
{
    if (empty(que))
    {
        return -1;
    }
    return que->first->data;
}

int back(queue* que)
{
    if (empty(que))
    {
        return -1;
    }
    return que->last->data;
}

int main(void)
{
    int N = 0;
    scanf("%d", &N);
    char cmd[6];
    queue que;
    int data;
    init(&que);
    for (int i = 0; i < N; i++)
    {
        scanf("%s", cmd);
        if (!strcmp(cmd, "push"))
        {
            scanf("%d", &data);
            push(&que ,data);
        }
        else if (!strcmp(cmd, "pop"))
        {
            printf("%d\n", pop(&que));
        }
        else if (!strcmp(cmd, "size"))
        {
            printf("%d\n", size(&que));
        }
        else if (!strcmp(cmd, "empty"))
        {
            printf("%d\n", empty(&que));
        }
        else if (!strcmp(cmd, "front"))
        {
            printf("%d\n", front(&que));
        }
        else if (!strcmp(cmd, "back"))
        {
            printf("%d\n", back(&que));
        }
    }
}