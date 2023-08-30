#include <stdio.h>

long long dp[1000010];

int main(void)
{
    int T = 0;
    scanf("%d", &T);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i <= 1000000; i++)
    {
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3])%1000000009;
    }
    int n = 0;
    for (int i = 0; i < T; i++)
    {
        scanf("%d", &n);
        printf("%d\n", dp[n]);
    }
}