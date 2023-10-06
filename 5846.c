#include <stdio.h>
#include <stdlib.h>

int N;
int grids[500+10][500+10];
int visited[500+10][500+10];
int checked[500+10][500+10];

typedef struct kan
{
    int x, y;
} kan;
kan queue[500*500+10];
int wp, rp;

void enqueue(int x, int y)
{
    queue[wp].x = x;
    queue[wp++].y = y;
}
kan dequeue() {return queue[rp++];}
int empty() {return wp==rp;}
int max_height = 0;
int min_height = 0;

void InputData(void){
    scanf("%d", &N);
    for (int i=0; i<N; i++){     // 세로
        for (int j=0; j<N; j++){    // 가로
            scanf("%d", &grids[i][j]);
            if (grids[i][j] > max_height) 
            {
                max_height = grids[i][j];
            }
        }
    }    
    // printf("%d\n", min_height);
}

void resetVisited()
{
    for (int yidx = 0; yidx < N; yidx++)
    {
        for (int xidx = 0; xidx < N; xidx++)
        {
            visited[yidx][xidx] = 0;
        }
    }
}

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int absi(int x)
{
    if (x < 0) return -x;
    return x;
}

int BFS(int sx, int sy, int diff)
{
    wp = rp = 0;
    enqueue(sx, sy);
    // printf("enqueue %d %d, %d\n", sx, sy, grids[sy][sx]);
    visited[sy][sx] = 1;
    int area = 1;
    kan next;
    int x_next, y_next;
    while(!empty())
    {
        next = dequeue();
        // printf("dequeue %d %d\n", next.x, next.y);
        for (int i = 0; i < 4; i++)
        {
            x_next = next.x + dx[i]; y_next = next.y + dy[i];
            if (!(0 <= x_next && x_next < N && 0 <= y_next && y_next < N)) continue;
            // 방문 안했으면서 이전 칸과 크기 차이가 diff보다 작거나 같을 때
            if (visited[y_next][x_next] == 0 && absi(grids[y_next][x_next] - grids[next.y][next.x]) <= diff)
            {
                enqueue(x_next, y_next);
                // printf("1. enqueue %d %d, %d, diff:%d\n", x_next, y_next, grids[y_next][x_next], diff);
                visited[y_next][x_next] = 1;
                area++;
            }
        }
    }
    return area;
}

int max(int a, int b)
{
    if (a > b) return a;
    return b;
}

int check(int diff)
{
    int area = 0;
    for (int yidx = 0; yidx < N; yidx++)
    {
        for (int xidx = 0; xidx < N; xidx++)
        {
            if(visited[yidx][xidx] == 1) continue;
            // printf("BFS starts at %d %d\n", xidx, yidx);
            area = max(area, BFS(xidx, yidx, diff));
        }
    }
    return area;    
}

int solve()
{
    int avail = -1;
    int min_avail = 1<<29;    
    int s = min_height; int e = max_height;
    if (s == e) return 0;
    int area;
    // printf("min:%d, max:%d\n", s, e);
    while(s <= e)
    {
        resetVisited();
        int mid = (s + e) / 2;
        // printf("Visited Reset, mid is %d, s:%d, e:%d\n", mid, s, e);
        area = check(mid);
        if(area >= (N*N + 1) / 2) // 이 mid값이 가능하다면
        {
            // 마지막을 낮게
            avail = mid;
            e = mid - 1;
            if (min_avail > avail) 
            {
                min_avail = avail;
                // printf("min_avail:%d\n", min_avail);
            }
        }
        else // 불가능하면 처음을 높게
        {
            s = mid + 1;
        }
    }
    // printf("BSEARCHDONE, s:%d , e:%d\n", s, e);
    return min_avail;
}

int main(void){
    int ans = -1;

    InputData();// 입력받는 부분
    ans = solve();
    printf("%d\n", ans);// 출력하는 부분
    return 0;
}