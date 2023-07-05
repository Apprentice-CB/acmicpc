#include <stdio.h>
#include <stdlib.h>

int time = 0;

typedef struct node
{
    int weight;
    int position;
    struct node* next;
} node;

typedef struct queue
{
    struct node* first;
    struct node* last;
    int total_weight;
    int length;
    int max_weight;
    int max_length;
} queue;

void initQueue(queue* que);
void enqueue_bridge(queue* bridge, queue* que);
void dequeue(queue* que);
void dequeue_bridge(queue* bridge);

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
    newNode->position = que->max_length;
    newNode->next = NULL;
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

void enqueue_bridge(queue* bridge, queue* que)
{
    time++;
    node* newNode = (node*)malloc(sizeof(node));
    if (que->first != NULL)
    {
        newNode->weight = que->first->weight;
        newNode->position = bridge->max_length;
        newNode->next = NULL;    
    }
    else
    {
        newNode->weight = 0;
        newNode->position = 0;
        newNode->next = NULL;
    }

    if (bridge->first == NULL)
    {
        bridge->first = newNode;
        bridge->last = newNode;
        bridge->total_weight += newNode->weight;
        //printf("1. enq to bridge %d, total_weight %d, cur time %d\n", que->first->weight, bridge->total_weight, time);
        dequeue(que);
    }
    else
    {
        node* tempNode = bridge->first;
        while(1)
        {
            tempNode->position--;
            tempNode = tempNode->next;
            if (tempNode == NULL)
            {
                break;
            }
        }

        if (bridge->first->position <= 0)
        {
            bridge->total_weight -= bridge->first->weight;
            //printf("2. dqu from bridge %d, total_weight %d, cur time %d\n", bridge->first->weight, bridge->total_weight, time);
            dequeue(bridge);
        }
    if (newNode->weight != 0)
    {
        if (bridge->total_weight + newNode->weight <= bridge->max_weight) 
        {
            bridge->total_weight = bridge->total_weight + newNode->weight;
            //printf("bridge's total weight %d, newNode_weight %d\n", bridge->total_weight, newNode->weight);            
            if (bridge->first == NULL)
            {
                bridge->first = newNode;
                bridge->last = newNode;
                //printf("3. enq to bridge %d, total_weight %d, cur time %d\n", newNode->weight, bridge->total_weight, time);
            }
            else
            {
                bridge->last->next = newNode;
                bridge->last = newNode;
                //printf("4. push bridge/ weight %d and potision %d, and enqueue %d, cur time %d\n", bridge->first->weight, bridge->first->position, newNode->weight, time);
            }
            dequeue(que);
        }
        else   // push는 아닌데 밀기만 하고 끝나는 case
        {
            //printf("5. push bridge weight %d and potision %d, cur time %d\n", bridge->first->weight, bridge->first->position, time);
            free(newNode);
        }
    }
    }
    
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
        que->first = tempNode->next;
        free(tempNode);
    }
}

void dequeue_bridge(queue* bridge)
{
    node* tempNode = bridge->first;
    if (tempNode == NULL)
    {
        return;
    }
    else
    {
        if (tempNode->position > 1)
        {
            while(1)
            {
                tempNode->position--;
                tempNode = tempNode->next;
                if (tempNode == NULL)
                {
                    break;
                }
            }
        }
        else
        {
            bridge->total_weight -= tempNode->weight;
            bridge->first = tempNode->next;
            free(tempNode); 
        }
    }
}

void next(queue* bridge, queue* que)
{
    time++;
    if (que->first != NULL) {
        if (bridge->total_weight + que->first->weight <= bridge->max_weight)
        {
            enqueue_bridge(bridge, que);
        }
        else
        {
            enqueue_bridge(bridge, que);
        }
    }
    else
    {
        dequeue_bridge(bridge);
    }
}


int main(void)
{
    int n = 0;
    int w = 0;
    int L = 0;
    queue* q = (queue*)malloc(sizeof(queue));
    queue* b = (queue*)malloc(sizeof(queue));
    scanf("%d %d %d", &n, &w, &L);
    initQueue(q);
    initQueue(b);
    b->max_length = w;
    b->max_weight = L;
    int cur = 0;
    for (int i = 0; i < n; i++)
    {
        scanf(" %d", &cur);
        enqueue(q, cur);
    }

    while(1)
    {
        if (q->first == NULL && b->first == NULL)
        {
            break;
        }
        enqueue_bridge(b, q);
    }
    printf("%d", time);
}