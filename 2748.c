#include <stdio.h>

int main(void)
{
    long long ar[91];
    ar[0] = 0;
    ar[1] = 1;
    ar[2] = 1;
    int n = 0;
    scanf("%d", &n);
    for (int i = 3; i <= n; i++)
    {
        ar[i] = ar[i-1] + ar[i-2];
    }
    printf("%lld", ar[n]);
}