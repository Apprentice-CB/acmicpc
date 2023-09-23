#include <stdio.h>
#include <stdlib.h>

int N;
int arr[60];

int compare(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int main(void)
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    qsort(arr, N, sizeof(int), compare);
    printf("%d\n", arr[0]*arr[N-1]);
}