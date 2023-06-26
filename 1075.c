#include <stdio.h>

int main(void)
{
    int N = 0;
    int F = 0;
    scanf("%d %d", &N, &F);
    N = (N / 100);
    N = N * 100;
    int cnt = 0;
    while(N % F != 0)
    {
        N++;
    }
    if (N % 100 < 10)
    {
        printf("0%d", N%100);
    }
    else
    {
        printf("%d", N%100);
    }
}