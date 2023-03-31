#include <stdio.h>
#include <math.h>

int main(void)
{
    int N = 0;
    scanf("%d", &N);
    printf("%lld", (long long)pow(pow(2, N) + 1, 2));
}