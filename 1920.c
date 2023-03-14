#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b)
{
    int aa = *(int*)a;
    int bb = *(int*)b;
    if (aa > bb)
    {
        return 1;
    }
    else if (aa == bb)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

int binary_search(int* arr, int N, int tgt)
{
    int first = 0;
    int last = N-1;
    int mid = (first + last) / 2;
    while (first <= last)
    {
        if (arr[mid] == tgt)
        {
            return 1;
        }
        else if (arr[mid] < tgt)
        {
            first = mid + 1;
        }
        else
        {
            last = mid - 1;
        }
        mid = (first + last) / 2;
    }
    return 0;
}

int main(void)
{
    int N = 0;
    int M = 0;
    scanf("%d", &N);
    int* arr = (int*)malloc(sizeof(int)*N);
    int input = 0;
    for (int i = 0; i < N; i++)
    {
        scanf(" %d", arr+i);
    }
    scanf("%d", &M);
    
    int* search = (int*)malloc(sizeof(int)*M);
    for (int i = 0; i < M; i++)
    {
        scanf(" %d", search+i);
    }
    qsort(arr, N, sizeof(int), compare);

    for (int i = 0; i < M; i++)
    {
        printf("%d\n", binary_search(arr, N, search[i]));
    }
}