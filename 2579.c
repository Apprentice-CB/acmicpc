#include <stdio.h>

int N;
int stair[310];
int dp[310];

void getInput()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &stair[i]);
    }
}

int max(int a, int b)
{
    if (a > b) return a;
    return b;
}

int main(void)
{
    getInput();
    dp[0] = 0;
    dp[1] = stair[1];
    dp[2] = stair[1] + stair[2];
    for (int i = 3; i <= N; i++)
    {
        dp[i] = stair[i] + max(dp[i-2], dp[i-3] + stair[i-1]);
    }
    printf("%d\n", dp[N]);
    return 0;
}