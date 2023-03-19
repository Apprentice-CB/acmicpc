#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(void)
{
    int n = 0;
    int sum = 0;
    bool check = false;
    scanf("%d", &n);
    while (n != -1)
    {   
        for (int i = 1; i <= n-1; i++)
        {
            if (n % i == 0)
            {
                sum += i;
            }
        }
        if (n == 1)
        {
            sum = 1;
        }
        if (n == sum)
        {
            printf("%d = 1", n);
            for (int i = 2; i <= n-1; i++)
            {
                if (n % i == 0)
                {
                    printf(" + %d", i);
                }
            }
            printf("\n");
        }
        else
        {
            printf("%d is NOT perfect.\n", n);
        }
        sum = 0;
        scanf("%d", &n);
    }
}