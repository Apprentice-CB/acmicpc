#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int N = 0;
    int M = 0;
    scanf("%d %d", &N, &M);
    int* arr = (int*)malloc(sizeof(int)*N);
    memset(arr, 0, sizeof(int)*N);
    int i = 0;
    int j = 0;
    int k = 0;
    for (int iter = 0; iter < M; iter++)
    {
        scanf("%d %d %d", &i, &j, &k);
        for (int idx = i-1; idx < j; idx++)
        {
            arr[idx] = k;
        }
    }

    for (int idx = 0; idx < N; idx++)
    {
        printf("%d ", arr[idx]);
    }
    return 0;
}