#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int value;
    struct node* next;
    struct node* prev;
} node;

typedef struct deque
{
    struct node* first;
    struct node* last;
    int size;
} deque;

void initDeque(deque* dqe)
{
    dqe->first = NULL;
    dqe->last = NULL;
    dqe->size = 0;
}

int size(deque* dqe)
{
    return dqe->size;
}

int empty(deque* dqe)
{
    return (dqe->first == NULL);
}

void push_front(deque* dqe, int value)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->value = value;
    newNode->next = NULL;
    if (dqe->first == NULL)
    {   
        dqe->first = newNode;
        dqe->last = newNode;
        newNode->prev = NULL;
    }
    else
    {
        dqe->first->next = newNode;
        newNode->prev = dqe->first;
        dqe->first = newNode;
    }
    dqe->size++;
}

void push_back(deque* dqe, int value)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->value = value;
    newNode->prev = NULL;
    if (dqe->first == NULL)
    {
        dqe->first = newNode;
        dqe->last = newNode;
        newNode->next = NULL;
    }
    else
    {
        dqe->last->prev = newNode;
        newNode->next = dqe->last;
        dqe->last = newNode;
    }
    dqe->size++;
}

int pop_front(deque* dqe)
{
    if (empty(dqe))
    {
        return -1;
    }
    node* tempNode = dqe->first;
    int value = tempNode->value;
    dqe->first = tempNode->prev;
    free(tempNode);
    dqe->size--;
    if (dqe->size == 1)
    {
        dqe->last = dqe->first;
    }
    else if (dqe->size == 0)
    {
        dqe->first = dqe->last = NULL;
    }
    return value;
}

int pop_back(deque* dqe)
{
    if (empty(dqe))
    {
        return -1;
    }
    node* tempNode = dqe->last;     // 마지막 노드 갖고오기
    int value = tempNode->value;    // 값 추출
    dqe->last = tempNode->next;     
    free(tempNode);
    dqe->size--;
    if (dqe->size == 1)
    {
        dqe->first = dqe->last;
    }
    else if (dqe->size == 0)
    {
        dqe->first = dqe->last = NULL;
    }
    return value;
}


int front(deque* dqe)
{
    if (empty(dqe))
    {
        return -1;
    }
    else
    {
        return dqe->first->value;
    }
}

int back(deque* dqe)
{
    if (empty(dqe))
    {
        return -1;
    }
    else
    {
        return dqe->last->value;
    }
}

int main() 
{
    int N = 0;
    scanf("%d", &N);
    deque* dqe = (deque*)malloc(sizeof(deque));
    initDeque(dqe);
    char cmd[15];
    int data = 0;
    for (int i = 0; i < N; i++)
    {
        scanf("%s", cmd);
        if (!strcmp("push_back", cmd))
        {
            scanf("%d", &data);
            push_back(dqe, data);
        }
        else if (!strcmp("push_front", cmd))
        {
            scanf("%d", &data);
            push_front(dqe, data);
        }
        else if (!strcmp("pop_front", cmd))
        {
            printf("%d\n", pop_front(dqe));
        }
        else if (!strcmp("pop_back", cmd))
        {
            printf("%d\n", pop_back(dqe));
        }
        else if (!strcmp("size", cmd))
        {
            printf("%d\n", size(dqe));
        }
        else if (!strcmp("empty", cmd))
        {
            printf("%d\n", empty(dqe));
        }
        else if (!strcmp("front", cmd))
        {
            printf("%d\n", front(dqe));
        }
        else if (!strcmp("back", cmd))
        {
            printf("%d\n", back(dqe));
        }
        else
        {
            /* do nothing */
        }
    }
    return 0;
}