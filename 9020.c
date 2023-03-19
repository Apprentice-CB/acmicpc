#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_prime(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}


int main(void)
{
    int T = 0;
    scanf("%d", &T);
    int num = 0;
    int k_p = 0;
    for (int i = 0 ; i < T; i++)
    {
        scanf("%d", &num);
        for (int k = num / 2; k >= 2; k--)
        {
            k_p = num - k;
            if (is_prime(k) && is_prime(k_p))
            {
                printf("%d %d\n", k, k_p);
                break;
            }

        }
    }
}