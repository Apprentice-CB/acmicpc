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
    int node_number = 0;
    temp_node = q->head;
    node_number = temp_node->number;
    q->head = q->head->next;
    if (q->cnt == 1)
    {
        q->head = NULL;
        q->tail = NULL;
    }
    q->cnt--;
    free(temp_node);
    return node_number;
}

int main(void)
{
    int x = 0;
    scanf("%d", &x);
    queue* que;
    int N = 0;
    int M = 0;
    int pri = 0;
    int order = 0;
    int pop_cnt = 0;
    int head_pri = 0;
    node* cur_node = (node*)malloc(sizeof(node)); 
    node* temp_node = (node*)malloc(sizeof(node));
    for (int i = 0; i < x; i++)
    {
        que = (queue*)malloc(sizeof(queue));
        init(que);
        pop_cnt = 0;
        scanf("%d %d", &N, &M);
        for (int nidx = 0; nidx < N; nidx++)
        {
            scanf(" %d", &pri);
            push(que, nidx, pri);
        }
        
        /*
        cur_node = que->head;
        printf("number / priority\n");
        for (int nidx = 0; nidx < N; nidx++)
        {
            printf("%d %d\n", cur_node->number, cur_node->priority);
            cur_node = cur_node->next;
        }
        
        if (cur_node == NULL)
        {
            printf("next node == NULL\n");
            return 0;
        }
        */
        
        order = -1;
        if (N != 1)
        {
        while (order != M)
        {
            cur_node = que->head->next;
            head_pri = que->head->priority;
            //printf("start_node number: %d, head_pri: %d\n", cur_node->number, head_pri);
            while (cur_node != NULL)
            {
                if (cur_node->priority > head_pri)
                {
                    push_back(que);
                    cur_node = que->head->next;
                    head_pri = que->head->priority;
                    /*
                    printf("number / priority\n");
                    temp_node = que->head;
                    while (temp_node != NULL)
                    {
                        printf("%d %d\n", temp_node->number, temp_node->priority);
                        temp_node = temp_node->next;
                    }
                    */
                }
                else
                {
                    cur_node = cur_node->next;
                }
                
            }
            pop_cnt++;
            order = pop(que);
            //printf("order = %d, pop_cnt: %d\n", order, pop_cnt);
        }
        }
        if (N == 1)
        {
            printf("1\n");
        }
        else 
        {
            //printf("pop_cnt: %d\n", pop_cnt);
            printf("%d\n", pop_cnt);
        }
        free(que);
    }
    free(cur_node);
}