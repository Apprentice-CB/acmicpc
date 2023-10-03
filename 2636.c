#include <stdio.h>

int C, R;
int map[110][110];

typedef struct node
{
    int x, y, t;
} node;
node queue[10000+10];
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
    scanf("%d %d", &R, &C);
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }
}

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void getOut()
{   
    wp = rp = 0;
    enqueue(0, 0, 0);
    map[0][0] = 2;
    node next;
    int x_next, y_next;
    while (!empty())
    {
        next = dequeue();
        for (int i = 0; i < 4; i++)
        {
            x_next = next.x + dx[i]; y_next = next.y + dy[i];
            if (!(0 <= x_next && x_next < C && 0 <= y_next && y_next < R)) continue;
            if (map[y_next][x_next] == 0)
            {
                enqueue(x_next, y_next, 0);
                map[y_next][x_next] = 2;
            }            
        }
    }
}

int checkCheese()
{
    int cnt = 0;
    for (int yidx = 0; yidx < R; yidx++)
    {
        for (int xidx = 0; xidx < C; xidx++)
        {
            if (map[yidx][xidx] == 1) cnt++;
        }
    }
    return cnt;
}

void debugPrint()
{
    for (int yidx = 0; yidx < R; yidx++)
    {
        for (int xidx = 0; xidx < C; xidx++)
        {
            printf("%d ", map[yidx][xidx]);
        } printf("\n");
    }
    printf("\n");
}

void checkOut()
{
    wp = rp = 0;
    for (int yidx = 1; yidx < R-1; yidx++)
    {
        for (int xidx = 1; xidx < C-1; xidx++)
        {
            if (map[yidx][xidx] == 2)
            {
                for (int i = 0; i < 4; i++)
                {
                    if (map[yidx+dy[i]][xidx+dx[i]] == 0)
                    {
                        enqueue(xidx+dx[i], yidx+dy[i], 0);
                        map[yidx+dy[i]][xidx+dx[i]] = 2;
                    }
                }
            }
        }
    }
    node next;
    int x_next, y_next;
    while(!empty())
    {
        next = dequeue();
        for (int i = 0; i < 4; i++)
        {
            x_next = next.x + dx[i]; y_next = next.y + dy[i];
            if (map[y_next][x_next] == 0)
            {
                enqueue(x_next, y_next, 0);
                map[y_next][x_next] = 2;
            }
        }
    }
}

int main(void)
{
    getInput();
    getOut();
    // debugPrint();
    int last = 0;
    int prev = 0;
    int time = 0;
    node next;
    while (1)
    {
        prev = last;
        last = checkCheese();
        if (last == 0)
        {
            break;
        }
        wp = 0; rp = 0;
        for (int yidx = 0; yidx < R; yidx++)
        {
            for (int xidx = 0; xidx < C; xidx++)
            {
                if (map[yidx][xidx] == 1)
                {
                    for (int i = 0; i < 4; i++)
                    {
                        if (map[yidx+dy[i]][xidx+dx[i]] == 2)
                        {
                            enqueue(xidx, yidx, 0);
                            break;
                        }
                    }
                }
            }
        }
        while(!empty())
        {
            next = dequeue();
            map[next.y][next.x] = 2;
        }
        time++;

        checkOut();

        // debugPrint();
    }
    printf("%d\n%d", time, prev);
    return 0;
}