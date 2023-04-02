#include <stdio.h>

int main(void)
{
    int N = 0;
    int K = 0;
    scanf("%d %d", &N, &K);
    int a = 1;
    int b = 1;
    for (int i = N-K+1; i <= N; i++)
    {
        a = a * i;
    }
    for (int i = 1; i <= K; i++)
    {
        b = b * i;
    }
    printf("%d", a / b);
}