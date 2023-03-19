#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int N = 0;
    int M = 0;
    scanf("%d %d", &N, &M);

    int **a = (int**)malloc(sizeof(int*)*N);
    int **b = (int**)malloc(sizeof(int*)*N);
    for (int i = 0; i < N; i++)
    {
        a[i] = (int*)malloc(sizeof(int)*M);
    }
    for (int i = 0; i < N; i++)
    {
        b[i] = (int*)malloc(sizeof(int)*M);
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("%d ", a[i][j] + b[i][j]);
        }
        printf("\n");
    }
    return 0;
}