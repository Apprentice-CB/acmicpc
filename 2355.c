#include <stdio.h>

int main(void)
{
    long long A = 0;
    long long B = 0;
    scanf("%lld %lld", &A, &B);
    if (B >= A)
        printf("%lld", (B-A+1)*(A+B)/2);
    else
        printf("%lld", (A-B+1)*(A+B)/2);
}