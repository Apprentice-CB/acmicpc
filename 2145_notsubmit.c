#include <stdio.h>

int main(void)
{
    int N = 0;
    int sum = 0;
    while(1)
    {
        scanf("%d", &N);
        if (N == 0)
        {
            return 0;
        }
        sum = 0;
        while(N > 0)
        {
            sum += N % 10;
            N = N / 10;
        }
        if (sum > 10)
        {
            N = 0;
            while (sum > 0)
            {
                N += sum % 10;
                sum = sum / 10;
            }
            printf("%d\n", N);
        }
        else
        {
            printf("%d\n", sum);
        }
    }
}