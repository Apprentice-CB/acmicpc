#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nidx = 0;
int midx = 0;
int area = 0;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int** map, int** visited, int N, int M, int n_start, int m_start, int dir)
{
    visited[n_start][m_start] = 1;
    area++;
    int n_next = 0;
    int m_next = 0;
    
}

int main(void)
{
    int N = 0;
    int M = 0;
    scanf("%d %d", &N, &M);
    int n_start = 0;
    int m_start = 0;
    int dir = 0;
    scanf("%d %d %d", &n_start, &m_start, &dir);

    int** map = (int**)malloc(sizeof(int*) * N);
    int** visited = (int**)malloc(sizeof(int*) * N);
    for (nidx = 0; nidx < N; nidx++)
    {
        map[nidx] = (int*)malloc(sizeof(int) * M);
        visited[nidx] = (int*)malloc(sizeof(int) * M);
        memset(visited[nidx], 0, sizeof(int) * M);
    }

    for (nidx = 0; nidx < N; nidx++);
    {
        for (midx = 0; midx < M; midx++)
        {
            scanf(" %d", &map[nidx][midx]);
        }
    }

    dfs(map, visited, N, M, n_start, m_start, dir);

}