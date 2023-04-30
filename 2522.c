#include <stdio.h>

int main(void)
{
    int N = 0;
    scanf("%d", &N);
    for (int i = 1; i <= N-1; i++)
    {
        for (int j = 1; j <= N-i; j++)
        {
            printf(" ");
        }
        for (int j = N-i; j < N; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    for (int i = 1; i <= N; i++)
    {
        printf("*");
    }
    printf("\n");

    for (int i = N-1; i >= 1; i--)
    {
        for (int j = 1; j <= N-i; j++)
        {
            printf(" ");
        }
        for (int j = N-i; j < N; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}