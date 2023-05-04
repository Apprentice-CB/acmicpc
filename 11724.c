#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint8_t graph[1001][1001];
uint8_t vertex[1001];
uint8_t visited[1001];

int DFS(uint8_t graph[][1001], int N, int start)
{
    visited[start] = 1;
    for (int i = 1; i <= N; i++)
    {
        if (visited[i] == 0 && graph[start][i] == 1)
        {
            DFS(graph, N, i);
        }
    }
}

int main(void)
{
    int N = 0;
    int M = 0;
    scanf("%d %d", &N, &M);
    int u = 0;
    int v = 0;
    int start = 0;
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
        vertex[u] = 1;
        vertex[v] = 1;
    }

    int cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        if (visited[i] == 0)
        {
            DFS(graph, N, i);
            cnt++;
        }
    }
    printf("%d", cnt);
}