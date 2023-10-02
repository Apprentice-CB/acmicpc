#include <stdio.h>
#include <stdlib.h>

int N, K;
int arr[5000000+10];

int compare(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int main(void)
{
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    qsort(arr, N, sizeof(int), compare);
    printf("%d\n", arr[K-1]);
    return 0;
}