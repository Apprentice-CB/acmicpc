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
    int k = 0;
    int *temp = (int*)malloc(sizeof(int)*N);
    for (int idx = 0; idx < M; idx++)
    {
        scanf("%d %d %d", &i, &j, &k);
        for (int tidx = 0; tidx < j-i+1; tidx++)
        {
            if (k+tidx <= j)
            {
                temp[tidx] = arr[k-1+tidx];
            }
            else
            {
                temp[tidx] = arr[k-1+tidx-(j-i+1)];
            }
        }
        for (int tidx = 0; tidx < j-i+1; tidx++)
        {
            arr[i-1+tidx] = temp[tidx];
        }
    }
    for (int idx = 0; idx < N; idx++)
    {
        printf("%d ", arr[idx]);
    }
    return 0;
}