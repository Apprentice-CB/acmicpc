#include <stdio.h>
#include <stdlib.h>

int N, M; // 강의의 수, M개의 블루레이
int arr[100000+10];
int max;

void getInput()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
        max += arr[i];
    }
}
int isPossible(int m)
{
    int cnt = 1;
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] > m) return 0;
        sum += arr[i];
        if (sum > m) // 블루레이에 들어갈 수 있으면
        {
            sum = arr[i];
            cnt++;
        }    
    }
    // printf("isPossible for %d, cnt:%d\n", m, cnt);
    if (cnt <= M) return 1;
    return 0;
}

int bSearch(int s, int e)
{
    int m;
    int sol = -1;

    while (s <= e)
    {
        m = (s + e) / 2;
        if (isPossible(m))
        {
            sol = m;
            e = m - 1;
        }
        else
        {
            s = m + 1;
        }
    }

    return sol;
}

int main(void)
{
    int ans = -1;
    getInput();

    ans = bSearch(1, max);
    printf("%d\n", ans);
    return 0;
}