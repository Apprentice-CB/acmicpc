#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int cnt = 0;

void dfs(int** graph, int* visited, int R, int N, int* print_arr)
{
    visited[R-1] = 1;
    print_arr[cnt] = R;
    cnt++;
    for (int node = 0; node < N; node++)
    {
        if (visited[node] == 0 && graph[R-1][node] == 1)
        // node를 방문하지 않고, 인접한 노드
        {
            print_arr[R-1] = node;
            dfs(graph, visited, node + 1, N, print_arr);
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
    int* print_arr;
    print_arr = (int*)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
    {
        graph[i] = (int*)malloc(sizeof(int) * N);
        memset(graph[i], 0, N * sizeof(int));
        visited[i] = 0;
        print_arr[i] = 0;
    }

    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &u, &v);
        graph[u-1][v-1] = 1;
        graph[v-1][u-1] = 1;
    }

    dfs(graph, visited, R, N, print_arr);

    for (int i = 0; i < N; i++)
    {
        printf("%d\n", print_arr[i]);
    }

    free(graph);
    free(visited);
    return 0;
}