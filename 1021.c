#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node* next;
    struct node* prev;
} node;

typedef struct cqueue
{
    node* head;
    node* tail;
    int cnt;
} cqueue;

void init(cqueue* cq)
{
    cq->head = NULL;
    cq->tail = NULL;
}

void push(cqueue* cq, int data)
{
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    cq->cnt++;
    if (cq->head == NULL)
    {
        cq->head = new_node;
        cq->tail = new_node;
        new_node->prev = new_node;
        new_node->next = new_node;
    }
    else
    {
        new_node->next = cq->head;
        cq->head->prev = new_node;
        cq->tail->next = new_node;
        new_node->prev = cq->tail;
        cq->tail = new_node;
    }
}

int pop(cqueue* cq)
{
    node* temp_node = (node*)malloc(sizeof(node));
    if (cq->head == NULL)
    {
        return 0;
    }
    temp_node = cq->head;
    int data = temp_node->data;
    if (cq->cnt == 1)
    {
        cq->tail->next = cq->head;
        cq->head->next = cq->tail;
        cq->tail->prev = cq->head;
        cq->head->prev = cq->tail;
        return data;
    }
    cq->tail->next = temp_node->next;
    cq->head = temp_node->next;
    cq->head->prev = cq->tail;
    free(temp_node);
    cq->cnt--;
    
    return data;
}

int main(void)
{
    int N = 0;
    int M = 0;
    scanf("%d %d", &N, &M);
    cqueue* cque = (cqueue*)malloc(sizeof(cqueue));
    init(cque);
    for (int i = 1; i <= N; i++)
    {
        push(cque, i);
    }

    int* input_arr = (int*)malloc(sizeof(int)*M);
    node* cur_node = (node*)malloc(sizeof(node));
    int left_cnt = 0;
    int right_cnt = 0;
    int sum = 0;
    int pop_data = 0;
    for (int i = 0; i < M; i++)
    {
        scanf(" %d", input_arr+i);
        left_cnt = 0;
        right_cnt = 0;
        cur_node = cque->head;
        while (cur_node->data != input_arr[i])
        {
            left_cnt++;
            cur_node = cur_node->next;
        }
        cur_node = cque->head;
        while (cur_node->data != input_arr[i])
        {
            right_cnt++;
            cur_node = cur_node->prev;
        }
        cque->head = cur_node;
        cque->tail = cur_node->prev;
        int pop_data = pop(cque);
        if (left_cnt > right_cnt)
        {
            sum += right_cnt;
        }
        else
        {
            sum += left_cnt;
        }
    }
    printf("%d\n", sum);
    return 0;
}