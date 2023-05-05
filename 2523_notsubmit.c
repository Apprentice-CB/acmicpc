#include <stdio.h>

int main(void)
{
    int N = 0;
    scanf("%d", &N);
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("*");
        }
        for (int j = i; j < N; j++)
        {
            printf(" ");
        }
        printf("\n");
    }
    for (int i = 0; i < N; i++)
    {
        printf("*");
    }
    printf("\n");
    for (int i = N+1; i < 2*N; i++)
    {
        for (int j = i; j < 2*N; j++)
        {
            printf("*");
        }
        for (int j = N+1; j < i; j++)
        {
            printf(" ");
        }
        printf("\n");
    }
}