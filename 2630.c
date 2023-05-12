#include <stdio.h>

int map[128][128] = {0, };
int white = 0;
int blue = 0;

void dnc(int map[][128], int N, int x, int y)
{
    int cnt = 0;
    if (N == 1)
    {
        if (map[x][y] == 1)
        {
            blue++;
        }
        else
        {
            white++;
        }
        return;
    }
    for (int xidx = x; xidx < x + N; xidx++)
    {
        for (int yidx = y; yidx < y + N; yidx++)
        {
            cnt += map[xidx][yidx];
        }
    }
    if (cnt == N*N)
    {
        blue++;
        return;
    }
    else if (cnt == 0)
    {
        white++;
        return;
    }
    else
    {
        dnc(map, N / 2, x, y);
        dnc(map, N / 2, x + N / 2, y);
        dnc(map, N / 2, x, y + N / 2);
        dnc(map, N / 2, x + N / 2, y + N / 2);
    }
}

int main(void)
{
    int N = 0;
    scanf("%d", &N);
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            scanf("%d", &map[x][y]);
        }
    }

    dnc(map, N, 0, 0);
    printf("%d\n%d", white, blue);
}