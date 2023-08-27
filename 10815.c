#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
    if (*(int*)a > *(int*)b)
        return 1;
    else if (*(int*)a == *(int*)b)
        return 0;
    else
        return -1;
}

int main(void)
{
    int N = 0;
    scanf("%d", &N);
    int arr[500001];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    qsort(arr, N, sizeof(int), compare);

    int M = 0;
    scanf("%d", &M);
    int inp;
    int* find;
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &inp);
        find = bsearch(&inp, arr, N, sizeof(int), compare);
        if (find != NULL) 
            printf("1 ");
        else 
            printf("0 ");
    }
}