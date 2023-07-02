#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void)
{
    long long S = 0;
    scanf("%lld", &S);
    int N = 0;
    int i = 0;
    long long sum = 0;
    while(1)
    {
        sum += i;
        i++;
        N++;
        if (sum > S)
        {
            N--;
            break;
        }
    }
    printf("%d", N);
}