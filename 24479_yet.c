#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dfs(int** graph, int* visited, int N, int R)
{
    visited[R] = 1;
    for (int node = 0; node < N; node++)
    {
        if (visited[node] == 0)
        {
            dfs(graph, visited, N, node);
        }
    }
}

int main(void)
{
    int N = 0;
    int M = 0;
    int R = 0;
    int u = 0;
    int v = 0;
    int cnt = 0;
    scanf("%d %d %d", &N, &M, &R);
    int** graph;
    graph = (int**)malloc(sizeof(int*) * N);
    int* visited;
    visited = (int*)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
    {
        graph[i] = (int*)malloc(sizeof(int) * N);
        visited[i] = 0;
    }
    memset(graph, 0, N * N * sizeof(int));

    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &u, &v);
        graph[u-1][v-1] = 1;
        graph[v-1][u-1] = 1;
    }
    dfs(graph, visited, N, R-1);
    for (int i = 0; i < N; i++)
    {
        printf("%d\n", visited[i]);
    }
    free(graph);
    free(visited);
    return 0;
}