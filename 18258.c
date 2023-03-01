#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct node
{
    int value;
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

void push(queue* que, int newData)
{  
    node* newNode;
    newNode = (node*)malloc(sizeof(node));
    newNode->value = newData;
    newNode->next = NULL;
    if ((que->first == NULL))
    {
        que->first = newNode;
        que->last = newNode;
    }
    else
    {
        que->last->next = newNode;
        que->last = newNode;
    }
    que->size++;
}

void pop(queue* que)
{
    if (que->first == NULL)
    {
        printf("-1\n");
        return;
    }
    else 
    {
        node* first = que->first;
        printf("%d\n", first->value);
        que->first = first->next;
        free(first);
        que->size--;
    }
}

bool empty(queue* que)
{
    return que->first == NULL;
}

int size(queue* que)
{
    return que->size;
}

int front(queue* que)
{
    if (que->first == NULL)
    {
        return -1;
    }
    else 
    {
        node* tempNode = que->first;
        return tempNode->value;
    }
}

int back(queue* que)
{
    if (que->first == NULL)
    {
        return -1;
    }
    else
    {
        return que->last->value;
    }
}

int main() 
{
    int N = 0;
    scanf("%d", &N);
    queue que;
    init(&que);
    char order[6];
    int value;
    for (int i = 0; i < N; i++) {
        scanf("%s", order);
        if (!strcmp(order, "push"))
        {
            scanf("%d", &value);
            push(&que, value);
        }
        else if (!strcmp(order, "pop"))
        {
            pop(&que);
        }
        else if (!strcmp(order, "empty"))
        {
            printf("%d\n", empty(&que));
        }
        else if (!strcmp(order, "size"))
        {
            printf("%d\n", size(&que));
        }
        else if (!strcmp(order, "front"))
        {
            printf("%d\n", front(&que));
        }
        else if (!strcmp(order, "back"))
        {
            printf("%d\n", back(&que));
        }
        else
        {

        }
    }
    return 0;
}