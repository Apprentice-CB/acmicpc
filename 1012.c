#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int map[51][51] = {0, };
int visited[51][51] = {0, };
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void DFS(int map[][51], int M, int N, int x, int y)
{
    visited[y][x] = 1;
    int xnext = 0;
    int ynext = 0;
    for (int i = 0; i < 4; i++)
    {
        xnext = x + dx[i];
        ynext = y + dy[i];
        if (visited[ynext][xnext] == 0 && map[ynext][xnext] == 1)
        {   
            DFS(map, M, N, xnext, ynext);
        }
    }
}

int main(void)
{
    int T = 0;
    scanf("%d", &T);
    int N = 0;  // stands for y
    int M = 0;  // stands for x
    int K = 0;
    int a = 0;
    int b = 0;
    int cnt = 0;
    for (int i = 0; i < T; i++)
    {
        scanf("%d %d %d", &M, &N, &K);
        for (int j = 0; j < K; j++)
        {
            scanf("%d %d", &a, &b);
            map[b][a] = 1;
        }
        cnt = 0;
        /*
        for (int yidx = 0; yidx < N; yidx++)
        {
            for (int xidx = 0; xidx < M; xidx++)
            {
                printf("%d ", map[yidx][xidx]);
            }
            printf("\n");
        }
        */
        for (int yidx = 0; yidx < N; yidx++)
        {
            for (int xidx = 0; xidx < M; xidx++)
            {
                if (visited[yidx][xidx] == 0 && map[yidx][xidx] == 1)
                {
                    DFS(map, M, N, xidx, yidx);
                    cnt++;
                }
            }
        }
        memset(map, 0, sizeof(int) * 51 * 51);
        memset(visited, 0, sizeof(int) * 51 * 51);
        printf("%d\n", cnt);
    }
}