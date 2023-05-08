#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool visited[101][101] = {false, };
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void DFS_normal(char** map, int N, int x, int y)
{
    char color = map[x][y];
    visited[x][y] = true;
    int xidx = 0;
    int yidx = 0;
    for (int i = 0; i < 4; i++)
    {
        xidx = x + dx[i];
        yidx = y + dy[i];
        if (0 <= xidx && xidx < N && 0 <= yidx && yidx < N)
        {
            if (visited[xidx][yidx] == 0 && color == map[xidx][yidx])
            {
                DFS_normal(map, N, xidx, yidx);
            }
        }
    }
}

void DFS_disabled(char** map, int N, int x, int y)
{
    char color = map[x][y];
    visited[x][y] = true;
    int xidx = 0;
    int yidx = 0;
    for (int i = 0; i < 4; i++)
    {
        xidx = x + dx[i];
        yidx = y + dy[i];
        if (0 <= xidx && xidx < N && 0 <= yidx && yidx < N)
        {
            if (visited[xidx][yidx] == 0)
            {
                if (color == 'R')
                {
                    if (map[xidx][yidx] == 'R' || map[xidx][yidx] == 'G')
                    {
                        DFS_disabled(map, N, xidx, yidx);
                    }
                }
                else if (color == 'G')
                {
                    if (map[xidx][yidx] == 'R' || map[xidx][yidx] == 'G')
                    {
                        DFS_disabled(map, N, xidx, yidx);
                    }
                }
                else if (color == 'B')
                {
                    if (map[xidx][yidx] == 'B')
                    {
                        DFS_disabled(map, N, xidx, yidx);
                    }
                }
            }
        }
    }
}

int main(void)
{
    int N = 0;
    scanf("%d", &N);
    char** map;
    map = (char**)malloc(sizeof(char*) * N);
    for (int i = 0; i < N; i++)
    {
        map[i] = (char*)malloc(sizeof(char) * N);
        scanf("%s", map[i]);
    }
    
    int normal = 0;
    int disabled = 0;
    char color;
    for (int xidx = 0; xidx < N; xidx++)
    {
        for (int yidx = 0; yidx < N; yidx++)
        {
            if (visited[xidx][yidx] == false)
            {
                DFS_normal(map, N, xidx, yidx);
                normal++;
            }
        }
    }
    memset(visited, false, sizeof(bool)*101*101);
    
    for (int xidx = 0; xidx < N; xidx++)
    {
        for (int yidx = 0; yidx < N; yidx++)
        {
            if (visited[xidx][yidx] == false)
            {
                DFS_disabled(map, N, xidx, yidx);
                disabled++;
            }
        }
    }

    printf("%d %d", normal, disabled);
}