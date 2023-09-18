#include <stdio.h>

typedef struct pixel
{
    int x, y;
    int t; 
    char c;
} pixel;
pixel queue[1000*1000+10];
int wp, rp;

void enqueue(pixel p)
{
    queue[wp++] = p;
}
pixel dequeue() {return queue[rp++];}
int empty() {return wp==rp;}

int R, C; // 세로 가로
char map[1000+10][1000+10];

void getInput()
{
    scanf("%d %d", &R, &C);
    for (int i = 1; i <= R; i++)
    {
        scanf("%s", (map[i]+1));
    }
}

pixel getStart()
{
    for (int yidx = 1; yidx <= R; yidx++)
    {
        for (int xidx = 1; xidx <= C; xidx++)
        {
            if (map[yidx][xidx] == 'J')
            {
                pixel rt;
                rt.y = yidx;
                rt.x = xidx;
                rt.t = 0;
                return rt;
            }
        }
    }
}

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int BFS()
{
    pixel temp;
    for (int yidx = 1; yidx <= R; yidx++)
    {
        for (int xidx = 1; xidx <= C; xidx++)
        {
            if (map[yidx][xidx] == 'F')
            {
                temp.x = xidx; temp.y = yidx; temp.t = 0; temp.c = map[yidx][xidx];
                enqueue(temp);
                // printf("enqueue %d %d %d\n", temp.x, temp.y, temp.t);
            }
        }
    }
    
    for (int yidx = 1; yidx <= R; yidx++)
    {
        for (int xidx = 1; xidx <= C; xidx++)
        {
            if (map[yidx][xidx] == 'J')
            {
                temp.x = xidx; temp.y = yidx; temp.t = 0; temp.c = map[yidx][xidx];
                enqueue(temp);
            }
        }
    }

    pixel next; char next_c;
    int next_x, next_y;
    while(!empty())
    {
        next = dequeue();
        // printf("dequeue %d %d %d\n", next.x, next.y, next.t);
        if (next.c == 'J' && (next.y == 1 || next.y == R || next.x == 1 || next.x == C))
        {
            return next.t + 1;
        }
        for (int i = 0; i < 4; i++)
        {
            next_x = next.x + dx[i];
            next_y = next.y + dy[i];
            if (!(1 <= next_x && next_x <= C && 1 <= next_y && next_y <= R)) continue;
            if (next.c == 'J')
            {
                next_c = map[next_y][next_x];
                if (next_c == '#' || next_c == 'F' || next_c == 'J') continue;
                temp.x = next_x; temp.y = next_y; temp.t = next.t+1; temp.c = 'J';
                enqueue(temp);
                map[next_y][next_x] = 'J';
                
                // printf("enqueue %d %d %d, 'J'\n", temp.x, temp.y, temp.t);
            }
            if (next.c == 'F')
            {
                next_c = map[next_y][next_x];
                if (next_c == 'F' || next_c == '#') continue;
                temp.x = next_x; temp.y = next_y; temp.t = next.t+1; temp.c = 'F';
                enqueue(temp);
                map[next_y][next_x] = 'F';
                // printf("enqueue %d %d %d, 'F'\n", temp.x, temp.y, temp.t);
            }
        }
    }
    return -1;
}

int solve()
{
    int rt = 0;
    rt = BFS();
    return rt;
}

int main(void)
{
    getInput();
    int ans = -1;
    ans = solve();
    // for (int yidx = 1; yidx <= R; yidx++)
    // {
    //     for (int xidx = 1; xidx <= C; xidx++)
    //     {
    //         printf("%c", map[yidx][xidx]);
    //     } printf("\n");
    // }
    if (ans == -1)
    {
        printf("IMPOSSIBLE\n");
        return 0;
    }
    printf("%d\n", ans);
}