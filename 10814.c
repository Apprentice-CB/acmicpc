#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int age;
    int idx;
    char name[101];
} node;

int compare(const void* a, const void* b)
{
    node* first = (node*) a;
    node* second = (node*) b;

    if (first->age > second->age)
    {
        return 1;
    }
    else if (first->age == second->age)
    {
        if (first->idx < second->idx)
        {
            return -1;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return -1;
    }
    return 0;
}


int main(void)
{
    int N = 0;
    scanf("%d", &N);
    node* arr = (node*)malloc(sizeof(node)*N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %s", &arr[i].age, arr[i].name);
        arr[i].idx = i;
    }
    qsort(arr, N, sizeof(node), compare);
    for (int i = 0; i < N; i++)
    {
        printf("%d %s\n", arr[i].age, arr[i].name);
    }
}
