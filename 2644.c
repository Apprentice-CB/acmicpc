#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int map[101][101] = {0, };
int visited[101] = {0, };
int cnt = 1;
bool success = false;

void DFS(int n, int start, int end, int cnt)
{
    visited[start] = 1;
    if (start == end)
    {
        success = true;
        printf("%d", cnt);
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (map[start][i] == 1 && visited[i] == 0)
        {
            DFS(n, i, end, cnt+1);
            if (success)
            {
                break;
            }
        }
    }

}

int main(void)
{
    int n = 0;
    scanf("%d", &n);

    int x = 0;
    int y = 0;
    int a = 0;
    int b = 0;
    scanf("%d %d", &a, &b);
    int t = 0;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d %d", &x, &y);
        map[x][y] = 1;
        map[y][x] = 1;
    }

    DFS(n, a, b, 0);

    if (!success)
    {
        printf("-1\n");
    }
    
}