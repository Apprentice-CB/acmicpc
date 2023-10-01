#include <stdio.h>
#include <stdlib.h>

int N, M;   // 과자의 수, 조카의 수
int arr[1000000+10];

void getInput()
{
    scanf("%d %d", &M, &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
}

int compare(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int isPossible(int m)
{
    int T = N-1;
    int cnt = 0;
    while (arr[T] >= m)
    {
        cnt += arr[T] / m;
        T--;
    }
    if (cnt >= M) return 1;
    return 0;
}

int bslow(int s, int e)
{
    int m;
    int sol = -1;
    while(s<=e)
    {
        m = (s+e) / 2;
        // printf("Start with %d\n", m);
        if (isPossible(m))
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
    getInput();
    qsort(arr, N, sizeof(int), compare);
    int ans = bslow(1, arr[N-1]);
    printf("%d\n", ans);
    return 0;
}