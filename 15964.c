#include <stdio.h>

int main(void)
{
    long long A = 0;
    long long B = 0;
    scanf("%lld %lld", &A, &B);
    printf("%lld", (A+B)*(A-B));
}