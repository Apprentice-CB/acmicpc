#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min = 0;
int max = 0;
int area_max = 0;
int cur_area = 0;
int xidx = 0;
int yidx = 0;
int i = 0;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int** map, int** visited, int N, int x_start, int y_start)
{
    visited[x_start][y_start] = 1;
    int x_next = 0;
    int y_next = 0;
    for (int j = 0; j < 4; j++)
    {
        x_next = x_start + dx[j];
        y_next = y_start + dy[j];
        if (0 <= x_next && x_next < N && 0 <= y_next && y_next < N)
        {
            if (visited[x_next][y_next] == 0 && map[x_next][y_next] != 0)
            {
                dfs(map, visited, N, x_next, y_next);
            }
        }
    }
}

int main(void)
{
    int N = 0;
    scanf("%d", &N);
    int** map = (int**)malloc(sizeof(int*) * N);
    int** map_cpy = (int**)malloc(sizeof(int*) * N);
    int** visited = (int**)malloc(sizeof(int*) * N);
    for (i = 0; i < N; i++)
    {
        map[i] = (int*)malloc(sizeof(int) * N);
        map_cpy[i] = (int*)malloc(sizeof(int) * N);
        visited[i] = (int*)malloc(sizeof(int) * N);
    }

    for (xidx = 0; xidx < N; xidx++)
    {
        for (yidx = 0; yidx < N; yidx++)
        {
            scanf(" %d", &map[xidx][yidx]);
            if (map[xidx][yidx] > max)
            {
                max = map[xidx][yidx];
            }
            if (map[xidx][yidx] < min)
            {
                min = map[xidx][yidx];
            }
        }
    }

    for (int t = min; t <= max; t++)
    {
        // copy & visited reset
        for (i = 0; i < N; i++)
        {
            memcpy(map_cpy[i], map[i], sizeof(int) * N);
            memset(visited[i], 0, sizeof(int) * N);
        }
        cur_area = 0;
        // drown
        for (xidx = 0; xidx < N; xidx++)
        {
            for (yidx = 0; yidx < N; yidx++)
            {
                if (map_cpy[xidx][yidx] <= t)
                {
                    map_cpy[xidx][yidx] = 0;
                }
            }
        }
        // dfs        
        for (xidx = 0; xidx < N; xidx++)
        {
            for (yidx = 0; yidx < N; yidx++)
            {
                if (visited[xidx][yidx] == 0 && map_cpy[xidx][yidx] != 0)
                {
                    cur_area++;
                    dfs(map_cpy, visited, N, xidx, yidx);
                    if (cur_area > area_max)
                    {
                        area_max = cur_area;
                    }
                }
            }
        }
    }
    printf("%d", area_max);
}