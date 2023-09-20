#include <stdio.h>

#define MAXN (100)

int M, N, H; // 가로, 세로, 높이
int map[MAXN+5][MAXN+5][MAXN+5];
int visited[MAXN+5][MAXN+5][MAXN+5];

typedef struct node
{ 
    int x, y, z;
} node;
node queue[MAXN*MAXN*MAXN+10];
int wp, rp;
void enqueue(int x, int y, int z)
{
    queue[wp].x = x;
    queue[wp].y = y;
    queue[wp++].z = z;
}
node dequeue() {return queue[rp++];}
int empty() {return wp==rp;}

void getInput()
{
    scanf("%d %d %d", &M, &N, &H);
    for (int zidx = 0; zidx < H; zidx++)
    {
        for (int yidx = 0; yidx < N; yidx++)
        {
            for (int xidx = 0; xidx < M; xidx++)
            {
                scanf("%d", &map[zidx][yidx][xidx]);
            }
        }
    }
}

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int BFS()
{
    wp = rp = 0;
    for (int zidx = 0; zidx < H; zidx++)
    {
        for (int yidx = 0; yidx < N; yidx++)
        {
            for (int xidx = 0; xidx < M; xidx++)
            {
                if (map[zidx][yidx][xidx] == 1)
                {
                    enqueue(xidx, yidx, zidx);
                    // printf("enqueue %d %d %d\n", xidx, yidx, zidx);
                }
            }
        }
    }

    node next;
    int x_next, y_next, z_next;
    while(!empty())
    {
        next = dequeue();
        // printf("dequeue %d %d %d\n", next.x, next.y, next.z);
        for (int i = 0; i < 6; i++)
        {
            x_next = next.x + dx[i]; y_next = next.y + dy[i]; z_next = next.z + dz[i];
            if (!(0 <= x_next && x_next < M)) continue;
            if (!(0 <= y_next && y_next < N)) continue;
            if (!(0 <= z_next && z_next < H)) continue;
            if (map[z_next][y_next][x_next] == 0)
            {
                enqueue(x_next, y_next, z_next);
                // printf("enqueue %d %d %d\n", x_next, y_next, z_next);
                map[z_next][y_next][x_next] = map[next.z][next.y][next.x]+1;
            }
        }
    }


    int t = 0;
    for (int zidx = 0; zidx < H; zidx++)
    {
        for (int yidx = 0; yidx < N; yidx++)
        {
            for (int xidx = 0; xidx < M; xidx++)
            {
                if (map[zidx][yidx][xidx] == 0)
                {
                    return -1;
                }
                if (t < map[zidx][yidx][xidx])
                    t = map[zidx][yidx][xidx];
            }
        }
    }
    return t-1;
}

int main(void)
{
    getInput();
    int ans = BFS();
    printf("%d\n", ans);
}