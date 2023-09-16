#include <stdio.h>
#include <string.h>

#define MAXN (500)
int M, N; // 세로 가로
int map[MAXN+10][MAXN+10];
int dp[MAXN+10][MAXN+10];
int cnt;

void getInput()
{
    scanf("%d %d", &M, &N);
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }
}

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int DFS(int x, int y)
{
    if (dp[y][x] != -1) 
    {
        // printf("DFS break at %d %d, return %d\n", x, y, dp[y][x]);
        return dp[y][x];
    }
    if (x == N-1 && y == M-1) // 종료 조건
    {
        // printf("DFS done\n");    
        return 1;
    }
    dp[y][x] = 0;
    int x_next, y_next;
    for (int i = 0; i < 4; i++)
    {
        x_next = x + dx[i]; y_next = y + dy[i];
        if (!(0 <= x_next && x_next < N && 0 <= y_next && y_next < M)) continue;
        if (map[y_next][x_next] < map[y][x])
        {
            // printf("DFS in to %d %d from %d %d\n", x_next, y_next, x, y);
            // for (int yidx = 0; yidx < M; yidx++)
            // {
            //     for (int xidx = 0; xidx < N; xidx++)
            //     {
            //         printf("%d ", dp[yidx][xidx]);
            //     }
            //     printf("\n");
            // }
            dp[y][x] += DFS(x_next, y_next);
        }
    }
    return dp[y][x];
}

int main(void)
{
    memset(dp, -1, sizeof(dp));
    getInput();
    // for (int yidx = 0; yidx < M; yidx++)
    // {
    //     for (int xidx = 0; xidx < N; xidx++)
    //     {
    //         dp[yidx][xidx] = -1;
    //     }
    // }
    printf("%d\n", DFS(0, 0));
    // for (int yidx = 0; yidx < M; yidx++)
    // {
    //     for (int xidx = 0; xidx < N; xidx++)
    //     {
    //         printf("%d ", dp[yidx][xidx]);
    //     }
    //     printf("\n");
    // }    
}