#include <stdio.h>

int N, M;
int used[10];
int result[1000];

void DFS(int cnt)
{
    if (cnt >= M)
    {
        for (int j = 0; j < M; j++)
        {
            printf("%d ", result[j]);
        }
        printf("\n");
        return;
    }

    for (int i = 1; i <= N; i++)
    {
        if (used[i] == 1) continue;
        result[cnt] = i;
        used[i] = 1;
        DFS(cnt+1);
        used[i] = 0;
    }
}

int main(void)
{
    scanf("%d %d", &N, &M);
    DFS(0);
    return 0;
}