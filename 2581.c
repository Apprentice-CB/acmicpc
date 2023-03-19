#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int is_prime(int num)
{
    if (num == 1)
    {
        return 0;
    }
    for (int i = num-1; i > 1; i--)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main(void)
{
    int M = 0;
    int N = 0;
    scanf("%d", &M);
    scanf("%d", &N);
    int prime_sum = 0;
    int prime_min = 0;
    bool prime_check = false;
    for (int i = M; i <= N; i++)
    {
        if (is_prime(i))
        {
            if(!prime_check)
            {
                prime_check = true;
                prime_min = i;
            }
            prime_sum += i;
        }
    }
    if (!prime_check)
    {
        printf("-1");
        return 0;
    }
    printf("%d\n%d", prime_sum, prime_min);
    return 0;
}