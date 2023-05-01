#include <stdio.h>
#include <stdlib.h>

int compare(const void* x, const void* y)
{
    int a = *(int*)x;
    int b = *(int*)y;
    if (a > b)
    {
        return 1;
    }
    else if (a == b)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

int main(void)
{
    int N = 0;
    scanf("%d", &N);
    int* arr = (int*)malloc(sizeof(int)*N);
    for (int i = 0; i < N; i++)
    {
        scanf(" %d", arr+i);
    }

    qsort(arr, N, sizeof(int), compare);
    
    for (int i = 0; i < N; i++)
    {
        printf("%d\n", arr[i]);
    }

}