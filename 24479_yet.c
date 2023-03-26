#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N = 0;
    int M = 0;
    int R = 0;
    int u = 0;
    int v = 0;
    scanf("%d %d %d", &N, &M, &R);
    int** graph;
    graph = (int**)malloc(sizeof(int*) * N);
    for (int i = 0; i < N; i++)
    {
        graph[i] = (int*)malloc(sizeof(int) * N);
    }
    memset(graph, 0, N * N * sizeof(int));

    for (int i = 0; i < M; i++)
    {
        
    }

}