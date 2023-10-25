#include <stdio.h>
#include <math.h>

long long A, B, C, D;
long long b, d;

int main(void)
{
    scanf("%lld %lld %lld %lld", &A, &B, &C, &D);
    b = B;
    int n = 0;
    while (b > 0)
    {
        b = b / 10;
        n++;
    }
    A = A * powl(10, n) + B;
    n = 0;
    d = D;
    while (d > 0)
    {
        d = d / 10;
        n++;
    }
    C = C * powl(10, n) + D;
    printf("%lld\n", A + C);
}