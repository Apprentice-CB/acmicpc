#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int n;
    struct node* next;
} node;

typedef struct stack
{
    struct node* first;
    struct node* last;
    int size;
} stack;

void initStack(stack* stk)
{
    stk->first = NULL;
    stk->last = NULL;
    stk->size = 0;
}

void push(stack* stk, int n)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->n = n;
    stk->size++;
    if (stk->first == NULL)
    {
        stk->first = newNode;
        stk->last = newNode;
        newNode->next = NULL;
    }
    else
    {
        newNode->next = stk->last;
        stk->last = newNode;        
    }
}

int pop(stack* stk)
{
    if (stk->last == NULL)
    {
        return -1;
    }
    node* lastNode = stk->last;
    int r = lastNode->n;
    stk->last = lastNode->next;
    stk->size--;
    free(lastNode);
    return r;
}

int last(stack* stk)
{
    if (stk->last == NULL)
    {
        return -1;
    }
    return stk->last->n;
}

int empty(stack* stk)
{
    if (stk->last == NULL)
    {
        return 1;
    }
    return 0;
}

int size(stack* stk)
{
    return stk->size;
}

int main(void)
{
    stack* stk = (stack*)malloc(sizeof(stack));
    initStack(stk);
    int N = 0;
    int in = 0;
    int cmd;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &cmd);
        switch (cmd)
        {
            case 1:
                scanf("%d", &in);
                push(stk, in);
                break;
            case 2:
                printf("%d\n", pop(stk));
                break;
            case 3:
                printf("%d\n", size(stk));
                break;
            case 4:
                printf("%d\n", empty(stk));
                break;
            case 5:
                printf("%d\n", last(stk));
                break;
            default:
                break;
        }
    }
}