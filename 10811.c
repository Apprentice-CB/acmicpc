#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int N = 0;
    int M = 0;
    scanf("%d %d", &N, &M);
    int *arr = (int*)malloc(sizeof(int)*N);
    for (int idx = 0; idx < N; idx++)
    {
        arr[idx] = idx + 1;
    }
    int i = 0;
    int j = 0;
    int temp = 0;
    for (int iter = 0; iter < M; iter++)
    {
        scanf("%d %d", &i, &j);
        for (int idx = 0; idx < (j-i+1)/2; idx++)
        {
            temp = arr[i-1+idx];
            arr[i-1+idx] = arr[j-1-idx];
            arr[j-1-idx] = temp;
        }
    }
    for (int idx = 0; idx < N; idx++)
    {
        printf("%d ", arr[idx]);
    }
    return 0;
}