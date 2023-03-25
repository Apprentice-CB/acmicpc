#include <stdio.h>

int main(void)
{
    long long n = 0;
    scanf("%lld", &n);
    printf("%lld\n3", n*(n-1)*(n-2)/6);
    return 0;
}