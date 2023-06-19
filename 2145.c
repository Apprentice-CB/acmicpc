#include <stdio.h>

int main(void)
{
    int N = 0;
    int sum = 0;
    int tmp1 = 0;
    int tmp2 = 0;
    while(1)
    {
        scanf("%d", &N);
        if (N == 0)
        {
            return 0;
        }
        sum = 0;
        while (N >= 10)
        {
            tmp1 = N;
            tmp2 = 0;
            while (tmp1 > 0)
            {
                tmp2 += tmp1 % 10;
                tmp1 /= 10;
            }
            N = tmp2;
        }
        printf("%d\n", N);
    }
}