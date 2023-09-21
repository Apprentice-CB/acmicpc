#include <stdio.h>

int K, N;
int arr[10000+10];
int max;

void getInput()
{
    max = 0;
    scanf("%d %d", &K, &N);
    for (int i = 0; i < K; i++)
    {
        scanf("%d", &arr[i]);
        if (arr[i] > max) {max = arr[i];}
    }
}

long long isPossible(long long m)
{
    long long cnt = 0;
    for (int i = 0; i < K; i++)
    {
        cnt += arr[i] / m;
    }
    if (cnt >= N) return 1;
    return 0;
}

long long solve(long long s, long long e)
{
    long long m;
    long long sol = -1;
    while (s <= e)
    {
        m = (s + e) / 2;
        if (isPossible(m)) // 가능하다면
        {
            sol = m;
            s = m + 1;
        }
        else
        {
            e = m - 1;
        }
    }
    return sol;
}

int main(void)
{
    long long ans = -1;
    getInput();
    ans = solve(1, max);
    printf("%lld\n", ans);
    return 0;
}