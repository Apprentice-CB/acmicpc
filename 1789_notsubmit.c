#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void)
{
    uint32_t S = 0;
    scanf("%d", &S);
    int N = 0;
    int i = 1;
    int sum = 0;
    while(1)
    {
        if (sum + i > S)
        {
            break;
        }
        sum += i;
        N++;
        i++;
    }
    printf("%d", N);
}