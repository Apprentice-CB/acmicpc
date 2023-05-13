#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int map[8][8] = {0, };
int map_cpy[8][8] = {0, };
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};


void dfs(int N, int M, int x, int y)
{
    int x_next = 0;
    int y_next = 0;
    for (int i = 0; i < 4; i++)
    {
        x_next = x + dx[i];
        y_next = y + dy[i];
        if (0 <= x_next && x_next < N && 0 <= y_next && y_next < M)
        {
            if (map_cpy[x_next][y_next] == 0)
            {
                map_cpy[x_next][y_next] = 2;
                dfs(N, M, x_next, y_next);
            }
        }
    }
}

int search(int N, int M)
{
    memcpy(map_cpy, map, sizeof(int) * 64);

    for (int nidx = 0; nidx < N; nidx++)
    {
        for (int midx = 0; midx < M; midx++)
        {
            if (map[nidx][midx] == 2)
            {
                //printf("DFS start, nidx:%d, midx:%d", nidx, midx);
                dfs(N, M, nidx, midx);
            }
        }
    }

    int cnt = 0;
    for (int nidx = 0; nidx < N; nidx++)
    {
        for (int midx = 0; midx < M; midx++)
        {
            if (map_cpy[nidx][midx] == 0)
            {
                cnt++;
            }
        }
    }
    return cnt;
}

int main(void)
{
    int N = 0;
    int M = 0;
    scanf("%d %d", &N, &M);

    for (int nidx = 0; nidx < N; nidx++)
    {
        for (int midx = 0; midx < M; midx++)
        {
            scanf(" %d", &map[nidx][midx]);
        }
    }

    int max = 0;
    int temp = 0;
    for (int fidx = 0; fidx < N * M - 2; fidx++)
    {
        if (map[fidx / M][fidx % M] == 0)
        {
            map[fidx / M][fidx % M] = 1;
            for (int sidx = fidx + 1; sidx < N * M - 1; sidx++)
            {
                if (map[sidx / M][sidx % M] == 0)
                {
                    map[sidx / M][sidx % M] = 1;
                    for (int tidx = sidx + 1; tidx < N * M; tidx++)
                    {
                        if (map[tidx / M][tidx % M] == 0)
                        {
                            map[tidx / M][tidx % M] = 1;
                            temp = search(N, M);
                            if (temp > max)
                            {
                                max = temp;
                            }
                            map[tidx / M][tidx % M] = 0;
                        }
                    }
                    map[sidx / M][sidx % M] = 0;
                }
            }
            map[fidx / M][fidx % M] = 0;
        }
    }
    printf("%d", max);
}