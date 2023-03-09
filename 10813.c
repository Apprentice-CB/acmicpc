#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int M = 0;
    int N = 0;
    scanf("%d %d", &N, &M);
    int *arr = (int*)malloc(sizeof(int) * N);
    for (int idx = 0; idx < N; idx++)
    {
        arr[idx] = idx+1;
    }
    int i = 0;
    int j = 0;
    int temp = 0;
    for (int idx = 0; idx < M; idx++)
    {
        scanf("%d %d", &i, &j);
        temp = arr[i-1];
        arr[i-1] = arr[j-1];
        arr[j-1] = temp;
    }

    for (int idx = 0; idx < N; idx++)
    {
        printf("%d ", arr[idx]);
    }
    return 0;
}