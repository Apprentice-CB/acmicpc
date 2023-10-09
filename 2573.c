#include <stdio.h>

int N, M;
int map[310][310];
int visited[310][310];

typedef struct node
{
    int x, y, t;
} node;
node queue[300*300+10];
int wp, rp;

void enqueue(int x, int y, int t)
{
    queue[wp].x = x;
    queue[wp].y = y;
    queue[wp++].t = t;
}
node dequeue() {return queue[rp++];}
int empty() {return wp==rp;}

void getInput()
{
    scanf("%d %d", &N, &M);
    for (int i = 0 ; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }
}

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void BFS(int x, int y)
{
    wp = rp = 0;
    enqueue(x, y, 0);
    visited[y][x] = 1;
    node next;
    int x_next, y_next;
    while (!empty())
    {
        next = dequeue();
        for (int i = 0; i < 4; i++)
        {
            x_next = next.x + dx[i]; y_next = next.y + dy[i];
            if (!(0 <= x_next && x_next < M && 0 <= y_next && y_next < N)) continue;
            if (visited[y_next][x_next] == 0 && map[y_next][x_next] != 0)
            {
                visited[y_next][x_next] = 1;
                enqueue(x_next, y_next, 0);
            }
        }
    }
}

int checktwo()
{
    for (int yidx = 0; yidx < N; yidx++)
    {
        for (int xidx = 0; xidx < M; xidx++)
        {
            visited[yidx][xidx] = 0;
        }
    }
    int cnt = 0;
    for (int yidx = 0; yidx < N; yidx++)
    {
        for (int xidx = 0; xidx < M; xidx++)
        {
            if (map[yidx][xidx] != 0 && visited[yidx][xidx] == 0)
            {
                BFS(xidx, yidx);
                cnt++;
            }
        }
    }
    if (cnt == 1) return 1;
    if (cnt == 0) return 2;
    return 0;
}

int temp[310][310];
void nok()
{
    for (int yidx = 0; yidx < N; yidx++)
    {
        for (int xidx = 0; xidx < M; xidx++)
        {
            temp[yidx][xidx] = 0;
        }
    }
    int x_next, y_next;
    for (int yidx = 0; yidx < N; yidx++)
    {
        for (int xidx= 0; xidx < M; xidx++)
        {
            if (map[yidx][xidx] > 0)
            {
                for (int i = 0; i < 4; i++)
                {
                    x_next = xidx + dx[i];
                    y_next = yidx + dy[i];
                    if (!(0 <= x_next && x_next < M && 0 <= y_next && y_next < N)) continue;
                    if (map[y_next][x_next] == 0)
                    {
                        temp[yidx][xidx]++;
                    }
                }
            }
        }
    }
    for (int yidx = 0; yidx < N; yidx++)
    {
        for (int xidx = 0; xidx < M; xidx++)
        {
            map[yidx][xidx] -= temp[yidx][xidx];
            if (map[yidx][xidx] < 0) map[yidx][xidx] = 0;
        }
    }
}

void debugPrint()
{
    printf("\n");
    for (int yidx = 0; yidx < N; yidx++)
    {
        for (int xidx = 0; xidx < M; xidx++)
        {
            printf("%d ", map[yidx][xidx]);
        } printf("\n");
    }
}

int solve()
{
    int T = 0;
    int cnt;
    while(1)
    {
        cnt = checktwo();
        if (cnt == 0) break;
        if (cnt == 2)
        {
            T = 0; break;
        }
        nok();
        T++;
        // debugPrint();
    }
    return T;
}

int main(void)
{
    getInput();
    int ans = solve();
    printf("%d\n", ans);
}