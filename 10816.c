#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b)
{
    int aa = *(int*) a;
    int bb = *(int*) b;
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


int binary_search(int* arr_N, int N, int val, int first, int last)
{
    int mid = 0;
    /* lower bound */
    while (last > first)
    {
        mid = (first + last) / 2;
        if (arr_N[mid] >= val)
        {
            last = mid;
        }
        else
        {
            first = mid + 1;
        }
    }
    int temp = last;
    
    
    /* upper bound */
    first = 0;
    last = N - 1;
    while (last > first)
    {
        mid = (first + last) / 2;
        if (arr_N[mid] > val)
        {
            last = mid;
        }
        else
        {
            first = mid + 1;
        }
    }
    if (arr_N[last] == val)
    {
        last = last + 1;
    }

    return last - temp;
}


int main()
{
    int N = 0;
    scanf("%d", &N);
    int* arr_N = (int*)malloc(sizeof(int)*N);
    for (int idx = 0; idx < N; idx++)
    {
        scanf(" %d", arr_N+idx);
    }
    
    int M = 0;
    scanf("%d", &M);
    int* arr_M = (int*)malloc(sizeof(int)*M);
    for (int idx = 0; idx < M; idx++)
    {
        scanf(" %d", arr_M+idx);
    }
    
    qsort(arr_N, N, sizeof(int), compare);

    for (int idx = 0; idx < M; idx++)
    {
        printf("%d ", binary_search(arr_N, N, arr_M[idx], 0, N-1));
    }
    
    return 0;
}
