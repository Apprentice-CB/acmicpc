#include <stdio.h>

int main(void)
{
    int T = 0;
    int N = 0;
    int M = 0;
    scanf("%d", &T);
    long long a = 0;
    long long b = 0;
    for (int i = 0; i < T; i++)
    {
        a = 1;
        b = 1;
        scanf("%d %d", &N, &M);
        if (M - N < N)
        {
            N = M - N;
        }
        for (int j = M; j >= M - N + 1; j--)
        {
            a = a * j;
        }
        for (int j = 1; j <= N; j++)
        {
            b = b * j;
        }
        printf("%lld\n", a / b);
    }
}