#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
    return *(int*)a >= *(int*)b;
}

typedef struct node
{
    int age;
    char name[100];
} node;

int main(void)
{
    int N = 0;
    scanf("%d", &N);
    node* arr = (node*)malloc(sizeof(node)*N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %s", &arr[i].age, arr[i].name);
    }
    qsort(arr, N, sizeof(node), compare);
    for (int i = 0; i < N; i++)
    {
        printf("%d %s\n", arr[i].age, arr[i].name);
    }
}
