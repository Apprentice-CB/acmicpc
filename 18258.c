#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _Node
{
    int value;
    struct node* next;
} node;

typedef struct _Queue
{
    struct node* first;
    struct node* last;
    int size;
} queue;

void init(queue* que)
{
    que->first = NULL;
    que->last = NULL;
}

void push(queue* que, int newData)
{  
    node* newNode;
    newNode = malloc(sizeof(node));
    if (que->first == NULL)
    {
        que->first = newNode;
        que->last = newNode;
    }
    newNode->next = que->last;
    newNode->value = newData;
    que->last = newNode;
    que->size++;
}

void pop(queue* que)
{
    node* first = que->first;
    printf("%d", first->value);
    que->first = first->next;
    free(que->first);
    que->size--;
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
    if (que->last == NULL)
    {
        return -1;
    }
    else
    {
        node* tempNode = que->last;
        return tempNode->value;
    }
}

int main() 
{
    int N = 0;
    scanf("%d", &N);
    queue* que = malloc(sizeof(queue));
    char order;
    int value;
    for (int i = 0; i < N; i++) {
        scanf("%c %d", &order, &value);
        switch (order)
        {
            case 'push':
            {
                push(que, value);
                break;
            }
            case 'pop':
            {
                pop(que);
                break;
            }
            case 'empty':
            {
                printf("%d", empty(que));
                break;
            }
            case 'size':
            {
                printf("%d", size(que));
                break;
            }
            case 'front':
            {
                printf("%d", front(que));
                break;
            }
            case 'back':
            {
                printf("%d", back(que));
                break;
            }
            default:
            {
                /* do nothing */
                break;
            }
        }
    }
    return 0;
}