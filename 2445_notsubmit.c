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
        for (int j = 0; j < 2*(N-i); j++)
        {
            printf(" ");
        }
        for (int j = 0; j < i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    for (int i = 0; i < 2*N; i++)
    {
        printf("*");
    }
    printf("\n");
    for (int i = N-1; i >= 1; i--)
    {
        for (int j = 0; j < i; j++)
        {
            printf("*");
        }
        for (int j = 0; j < 2*(N-i); j++)
        {
            printf(" ");
        }
        for (int j = 0; j < i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}