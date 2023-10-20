#include <stdio.h>

int A[1010];
int N;
int dp[1010];
void getInput()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
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
    dp[0] = 1;
    for (int i = 1; i < N; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (A[i] > A[j])
            {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    int max = 0;
    for (int i = 0; i < N; i++)
    {
        if (dp[i] > max) max = dp[i];
    }
    printf("%d\n", max);
    return 0;
}