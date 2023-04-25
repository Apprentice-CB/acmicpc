#include <stdio.h>

int main(void)
{
    long long a = 0;
    long long b = 0;
    long long c = 0;
    long long d = 0;
    long long k = 0;
    scanf("%lld", &k);
    scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
    if ((a * k + b) == (c * k + d))
    {
        printf("Yes %lld", a*k+b);
    }
    else
    {
        printf("No");
    }

}