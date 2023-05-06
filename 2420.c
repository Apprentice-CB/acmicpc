#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    long long N = 0;
    long long M = 0;
    scanf("%lld %lld", &N, &M);
    printf("%lld", llabs(N - M));
}