#include <stdio.h>

int main(void)
{
    int N = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf(" ");
        }
        for (int j = i; j < 2*N-1 - i; j++)
        {
            printf("*");
        }
        for (int j = 2*N-1 - i; j < 2*N-1; j++)
        {
            printf(" ");
        }
        if (i != N-1)
            printf("\n");
    }
}