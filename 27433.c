#include <stdio.h>
#include <stdlib.h>

long long factorial(long long N)
{
    if (N == 0)
    {
        return 1;
    }
    else if (N == 1)
    {
        return 1;
    }
    else
    {
        return N * factorial(N-1);
    }
}

int main(void)
{
    int N = 0;
    scanf("%d", &N);
    long long f = 0;
    printf("%lld", factorial(N));
}