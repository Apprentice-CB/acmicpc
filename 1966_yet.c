#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node 
{
    int number;
    int priority;
    struct node* next;
} node;

typedef struct queue
{
    int cnt;
    struct node* head;
    struct node* tail;
} queue;

void init(queue* q)
{
    q->head = NULL;
    q->tail = NULL;
    q->cnt = 0;
}

void push(queue* q, int num, int pri)
{
    node* new_node;
    new_node = (node*)malloc(sizeof(node));
    new_node->number = num;
    new_node->priority = pri;
    if (q->head == NULL)
    {
        q->head = new_node;
        q->tail = new_node;
        new_node->next = new_node;
    }
    else
    {
        q->tail->next = new_node;
        q->tail = new_node;
        new_node->next = NULL;
    }
    q->cnt++;
}

void push_back(queue* q)
{   
    q->tail->next = q->head;
    q->head = q->head->next;
    q->tail = q->tail->next;
    q->tail->next = NULL;
}

int pop(queue* q)
{
    node* temp_node = (node*)malloc(sizeof(node));
    q->head = temp_node;
    int number = temp_node->number;
    q->head = temp_node->next;
    free(temp_node);
    return number;
}

int main(void)
{
    int x = 0;
    scanf("%d", &x);
    queue* que = (queue*)malloc(sizeof(queue));
    init(que);
    int N = 0;
    int M = 0;
    int pri = 0;
    int order = 0;
    node* cur_node = (node*)malloc(sizeof(node));
    for (int i = 0; i < x; i++)
    {
        scanf("%d %d", &N, &M);
        for (int nidx = 0; nidx < N; nidx++)
        {
            scanf(" %d", &pri);
            push(que, nidx, pri);
        }
        /*
        cur_node = que->head;
        for (int nidx = 0; nidx < N; nidx++)
        {
            printf("%d ", cur_node->number);
            cur_node = cur_node->next;
        }
        */

        order = 0;
        cur_node = que->head;
        int head_pri = cur_node->priority;
        for (int qidx = 0; qidx < N; qidx++)
        {
            while (cur_node->next != NULL)
            {
                printf("%d ", cur_node->number);
                if (cur_node->priority > head_pri)
                {
                    push_back(que);
                    break;
                }
                cur_node = cur_node->next;
            }
            order = pop(que);
            if (order == M)
            {
                printf("%d\n", order);
                break;
            }
        }
    }
    free(que);
    free(cur_node);
}