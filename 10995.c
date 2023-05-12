#include <stdio.h>

int main(void)
{
    int N = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < 2 * N - 1; j++)
            {
                if (j % 2 == 1)
                {
                    printf(" ");
                }
                else
                {
                    printf("*");
                }
            }
        }
        else
        {
            for (int j = 0; j < 2 * N; j++)
            {
                if (j % 2 == 0)
                {
                    printf(" ");
                }
                else
                {
                    printf("*");
                }
            }   
        }
        printf("\n");
    }
}