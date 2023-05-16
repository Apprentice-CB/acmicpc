#include <stdio.h>

int main(void)
{
    int K = 0;
    int N = 0;
    int M = 0;
    scanf("%d %d %d", &K, &N, &M);
    int sum = K*N-M;
    if (sum > 0)
    {
        printf("%d", sum);
    }
    else
    {
        printf("0");
    }
}