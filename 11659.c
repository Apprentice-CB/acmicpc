#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int N = 0;
    int M = 0;
    scanf("%d %d", &N, &M);
    int* arr = (int*)malloc(sizeof(int)*N);
    for (int idx = 0; idx < N; idx++)
    {
        scanf(" %d", arr+idx);
    }
    int* sum_arr = (int*)malloc(sizeof(int)*(N+1));
    sum_arr[0] = 0;
    int sum = 0;
    for (int idx = 1; idx <= N; idx++)
    {
        sum += arr[idx-1];
        sum_arr[idx] = sum;
    }
    int i = 0;
    int j = 0;
    for (int idx = 0; idx < M; idx++)
    {
        scanf("%d %d", &i, &j);
        printf("%d\n", sum_arr[j]-sum_arr[i-1]);
    }
    return 0;
}