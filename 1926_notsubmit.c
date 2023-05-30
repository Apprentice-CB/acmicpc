#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cnt = 0;
int max = 0;
int cur = 0;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};


void dfs(int** map, int** visited, int n, int m, int n_start, int m_start)
{
    visited[n_start][m_start] = 1;
    int n_next = 0;
    int m_next = 0;
    for (int i = 0; i < 4; i++)
    {
        n_next = n_start + dx[i];
        m_next = m_start + dy[i];
        if (0 <= n_next && n_next < n && 0 <= m_next && m_next < m)
        {
            if (map[n_next][m_next] == 1 && visited[n_next][m_next] == 0)
            {
                cur++;
                dfs(map, visited, n, m, n_next, m_next);
            }
        }
    }
}

int main(void)
{
    int n = 0;
    int m = 0;
    scanf("%d %d", &n, &m);
    int** map = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++)
    {
        map[i] = (int*)malloc(sizeof(int) * m);
    }

    int** visited = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++)
    {
        visited[i] = (int*)malloc(sizeof(int) * m);
        memset(visited[i], 0, sizeof(int) * m);
    }

    for (int nidx = 0; nidx < n; nidx++)
    {
        for (int midx = 0; midx < m; midx++)
        {
            scanf(" %d", &map[nidx][midx]);
        }
    }

    for (int nidx = 0; nidx < n; nidx++)
    {
        for (int midx = 0; midx < m; midx++)
        {
            if (visited[nidx][midx] == 0 && map[nidx][midx] == 1)
            {
                cur = 1;
                cnt++;
                dfs(map, visited, n, m, nidx, midx);
                if (cur > max)
                {
                    max = cur;
                }
            }
        }
    }
    printf("%d\n%d", cnt, max);
}