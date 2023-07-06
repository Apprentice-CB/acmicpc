#include <stdio.h>
#include <stdlib.h>

int big(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

int main(void)
{
    int n = 0;
    scanf("%d", &n);
    int** dp = (int**)malloc(sizeof(int*)*n);
    for (int i = 0; i < n; i++)
    {
        dp[i] = (int*)malloc(sizeof(int)*n);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            scanf("%d", &dp[i][j]);
        }
    }

    int max = dp[0][0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0)
            {
                dp[i][j] += dp[i-1][j];
            }
            else if (j == i)
            {
                dp[i][j] += dp[i-1][j-1];
            }
            else
            {
                dp[i][j] += big(dp[i-1][j-1], dp[i-1][j]);
            }
            if (dp[i][j] > max)
            {
                max = dp[i][j];
            }
        }
    }
    printf("%d", max);
}