#include <stdio.h>

int N;
int map[100][100];

typedef struct node
{
    int x, y;
} node;
node queue[10000];
int wp, rp;
void enqueue(int x, int y)
{
    queue[wp].x = x;
    queue[wp++].y = y;
}
node dequeue() {return queue[rp++];}
int empty() {return wp==rp;}

int visited[100][100];

void getInput()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 1) map[i][j] = -1;
        }
    }
}

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void BFS(int x, int y, int cnt)
{
    wp = rp = 0;
    enqueue(x, y);
    visited[y][x] = 1;
    map[y][x] = cnt;
    node next;
    int x_next, y_next;
    while (!empty())
    {
        next = dequeue();
        for (int i = 0; i < 4; i++)
        {
            x_next = next.x + dx[i];
            y_next = next.y + dy[i];
            if (!(0 <= x_next && x_next < N && 0 <= y_next && y_next < N)) continue;
            if (visited[y_next][x_next] == 0 && map[y_next][x_next] != 0)
            {
                visited[y_next][x_next] = 1;
                map[y_next][x_next] = cnt;
                enqueue(x_next, y_next);
            }
        }
    }
}

void debugPrint()
{
    printf("\n");
    for (int yidx = 0; yidx < N; yidx++)
    {
        for (int xidx = 0; xidx < N; xidx++)
        {
            printf("%d ", map[yidx][xidx]);
        } printf("\n");
    }
}

int absi(int a)
{
    if (a > 0) return a;
    return -a;
}

int min(int a, int b)
{
    if (a > b) return b;
    return a;
}

int main(void)
{
    getInput();
    int num = 1;
    for (int yidx = 0; yidx < N; yidx++)
    {
        for (int xidx = 0; xidx < N; xidx++)
        {
            if (visited[yidx][xidx] == 0 && map[yidx][xidx] != 0)
            {
                BFS(xidx, yidx, num);
                num++;
            }
        }
    }
    // debugPrint();
    wp = rp = 0;
    for (int yidx = 0; yidx < N; yidx++)
    {
        for (int xidx = 0; xidx < N; xidx++)
        {
            if (map[yidx][xidx] != 0) enqueue(xidx, yidx);
        }
    }
    node next;
    int length = 0x7fffffff;
    while (!empty())
    {
        next = dequeue();
        int cur = map[next.y][next.x];
        for (int yidx = 0; yidx < N; yidx++)
        {
            for (int xidx = 0; xidx < N; xidx++)
            {
                if (map[yidx][xidx] != cur && cur != 0 && map[yidx][xidx] != 0)
                {
                    length = min(length, absi(xidx - next.x) + absi(yidx - next.y)-1);
                    // printf("xidx:%d, yidx:%d, map[%d][%d]:%d, next.x:%d, next.y:%d, map[%d][%d]:%d, len:%d\n", xidx, yidx, xidx, yidx,map[yidx][xidx], next.x, next.y, next.x, next.y, map[next.y][next.x], length);
                }
            }
        }
    }
    printf("%d\n", length);
}