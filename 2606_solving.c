#include <stdio.h>

int network[101][101] = {0, };

typedef struct node
{
    int data;
    struct node* next;
} node;

typedef struct queue
{
    struct node* first;
    struct node* last;
} queue;

int main(void)
{
    int N = 0;
    scanf("%d", &N);
    int r = 0;
    int c = 0;
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &r, &c);
        network[r][c] = 1;
        network[c][r] = 1;

    }
}