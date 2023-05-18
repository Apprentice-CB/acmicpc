#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int num;
    int weight;
    struct node* next;
} node;

void addNode(node* cur, int num, int weight)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->num = num;
    newNode->weight = weight;
    newNode->next = NULL;
    cur->next = newNode;
    printf("add Node at number %d, next number is %d // ", cur->num, newNode->num);
    cur = newNode;
    printf("now, current node number: %d\n", cur->num);
}

int main(void)
{
    int N = 0;
    int M = 0;
    scanf("%d %d", &N, &M);
    int* visited = (int*)malloc(sizeof(node)* (N+1));
    memset(visited, 0, sizeof(int) * (N+1));
    node* arr = (node*)malloc(sizeof(node) * (N+1));
    node** arr_last = (node**)malloc(sizeof(node*) * (N+1));
    for (int i = 1; i <= N; i++)
    {
        arr[i].num = 0;
        arr[i].weight = 0;
        arr[i].next = NULL;
        arr_last[i] = &arr[i];
    }

    int u = 0;
    int v = 0;
    int w = 0;
    for (int i = 0; i < N-1; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        arr[u].num = u;
        arr[v].num = v;

        addNode(arr_last[u], v, w);
        addNode(arr_last[v], u, w);
        arr_last[u] = arr_last[u]->next;
        arr_last[v] = arr_last[v]->next;
    }

    node* temp;
    for (int i = 1; i <= N; i++)
    {
        temp = &arr[i];
        printf("%d // ", i);
        while(temp != NULL)
        {
            printf("number: %d weight: %d\t", temp->num, temp->weight);
            temp = temp->next;
        }
        printf("\n");
    }

    node* cur;
    int result = 0;
    for (int i = 0; i < M; i++)
    {
        result = 0;
        scanf("%d %d", &u, &v);
        cur = &arr[u];
        visited[u] = 1;
        printf("number: %d, weight: %d \t", cur->num, cur->weight);

        printf("%d\n", result);
        memset(visited, 0, sizeof(int)*(N+1));
    }
}