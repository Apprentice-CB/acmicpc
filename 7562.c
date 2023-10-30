#include <stdio.h>

int T, I;
int sx, sy, ex, ey;
typedef struct node
{
    int x, y, t;
} node;
node queue[90000+10];
int wp, rp;

int visited[310][310];

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
    scanf("%d", &I);
    scanf("%d %d", &sx, &sy);
    scanf("%d %d", &ex, &ey);
}

int dx[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
int dy[8] = {-2, -2, -1, 1, 2, 2, 1, -1};

int solve()
{
    wp = rp = 0;
    for (int yidx = 0; yidx < I; yidx++)
    {
        for (int xidx = 0; xidx < I; xidx++)
        {
            visited[yidx][xidx] = 0;
        }
    }

    enqueue(sx, sy, 0);
    visited[sy][sx] = 1;

    node next;
    int nx, ny;
    while(!empty())
    {
        next = dequeue();
        for (int i = 0; i < 8; i++)
        {
            nx = next.x + dx[i]; ny = next.y + dy[i];
            if (!(0 <= nx && nx < I && 0 <= ny && ny < I)) continue;
            if (visited[ny][nx] == 0)   // 방문 안했으면
            {
                visited[ny][nx] = 1;
                enqueue(nx, ny, next.t+1);
                if (ny == ey && nx == ex)
                {
                    return next.t+1;
                }
            }
        }
    }
    return 0;
}

int main(void)
{
    int ans = -1;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        getInput();
        ans = solve();
        printf("%d\n", ans);
    }
    return 0;
}