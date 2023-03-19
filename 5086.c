#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N = 0;
    int M = 0;
    scanf("%d %d", &N, &M);
    while ((N != 0) && (M != 0))
    {
        if (M % N == 0)
        {
            printf("factor\n");
        }
        else if (N % M == 0)
        {
            printf("multiple\n");
        }
        else 
        {
            printf("neither\n");
        }
        scanf("%d %d", &N, &M);
    }
    return 0;
}