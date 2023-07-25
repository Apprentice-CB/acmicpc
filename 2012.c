#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
    return *(int*)a > *(int*)b;
}

int main(void)
{
    int N = 0;
    scanf("%d", &N);
    int* arr = (int*)malloc(sizeof(int)*N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    qsort(arr, N, sizeof(int), compare);
    long long sum = 0;
    for (int i = 1; i <= N; i++)
    {
        sum += abs(i - arr[i-1]);
    }
    printf("%lld", sum);
}