#include <stdio.h>
#define INF 987654321

int N, M;
int map[1010][1010];
int cost[1010];
int visited[1010];
int S, E;
void getInput()
{
    scanf("%d", &N);
    scanf("%d", &M);
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            map[i][j] = INF;
        }
        cost[i] = INF;
    }
    int a, b, c;
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        if (map[a][b] > c) map[a][b] = c;
    }
    scanf("%d %d", &S, &E);
}

int main(void)
{
    getInput();
    cost[S] = 0;
    int v;
    for (int i = 1; i <= N; i++)
    {
        int min = INF;
        for (int j = 1; j <= N; j++)
        {
            if(visited[j] == 0 && min > cost[j])
            {
                min = cost[j];
                v = j;
            }
        }
        visited[v] = 1;
        for (int j = 1; j <= N; j++)
        {
            if ((cost[j] > cost[v] + map[v][j]) && (map[v][j] != min))
            {
                cost[j] = cost[v] + map[v][j];
            }
        }
    }
    printf("%d\n", cost[E]);
    return 0;
}