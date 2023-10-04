#include <stdio.h>
#include <stdlib.h>

int N, M;
int bud[10000+10];

void getInput()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &bud[i]);
    }
    scanf("%d", &M);
}

int compare(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int isPossible(int m)
{
    int sum = M;
    for (int i = 0; i < N; i++)
    {
        if (bud[i] >= m)
        {
            sum -= m;
        }
        else
        {
            sum -= bud[i];
        }
    }
    if (sum >= 0) return 1;
    return 0;
}

int main(void)
{
    getInput();
    qsort(bud, N, sizeof(int), compare);

    int s = 1;
    int e = bud[N-1];
    int sol = -1;
    int m;
    while (s <= e)
    {
        m = (s + e) / 2;
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
    printf("%d\n", sol);
    return 0;
}