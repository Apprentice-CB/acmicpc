#include <stdio.h>

int x, y;
int map[1000+10][1000+10];
int visited[1000+10][1000+10];
typedef struct node
{
    int x, y, t;
} node;
node queue[1000*1000+10];
int wp, rp;
void enqueue(int x, int y, int t)
{
    queue[wp].x = x;
    queue[wp].t = t;
    queue[wp++].y = y;
}
node dequeue()
{
    return queue[rp++];
}
int empty() { return wp==rp; }

void getInput()
{
    scanf("%d %d", &y, &x);
    for (int yidx = 0; yidx < y; yidx++)
    {
        for (int xidx = 0; xidx < x; xidx++)
        {
            scanf("%d", &map[yidx][xidx]);
        }
    }
}

void printOutput()
{
    for (int yidx = 0; yidx < y; yidx++)
    {
        for (int xidx = 0; xidx < x; xidx++)
        {
            printf("%d ", visited[yidx][xidx]);
        }
        printf("\n");
    }
}

node getStart()
{
    for (int yidx = 0; yidx < y; yidx++)
    {
        for (int xidx = 0; xidx < x; xidx++)
        {
            if (map[yidx][xidx] == 2)
            {
                node temp;
                temp.x = xidx; temp.y = yidx;
                return temp;
            }
        }
    }
}

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void BFS(node start)
{
    wp = rp = 0;
    enqueue(start.x, start.y, 0);
    visited[start.y][start.x] = 0;
    // printf("enqueue %d %d 0\n", start.x, start.y);
    
    node next;
    int x_next, y_next;
    while(!empty())
    {
        next = dequeue();
        // printf("dequeue %d %d %d\n", next.x, next.y, next.t);
        for (int i = 0; i < 4; i++)
        {
            x_next = next.x + dx[i]; y_next = next.y + dy[i];
            if (!(0 <= x_next && x_next < x && 0 <= y_next && y_next < y)) continue;
            if (map[y_next][x_next] == 1 && visited[y_next][x_next] == 0)
            {
                enqueue(x_next, y_next, next.t+1);
                visited[y_next][x_next] = next.t+1;
                // printf("enqueue %d %d %d\n", x_next, y_next, next.t+1);
            }
        }
    }
}

int main(void)
{
    getInput();
    node start = getStart();

    BFS(start);

    for (int yidx = 0; yidx < y; yidx++)
    {
        for (int xidx = 0; xidx < x; xidx++)
        {
            if (map[yidx][xidx] == 1 && visited[yidx][xidx] == 0)
            {
                visited[yidx][xidx] = -1;
            }
        }
    }

    printOutput();
    return 0;    
}