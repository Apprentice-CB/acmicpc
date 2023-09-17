#include <stdio.h>
#define MAXH (12)
#define MAXW (6)
char map[MAXH+2][MAXW+2];
int visited[MAXH+2][MAXW+2];
void InputData(void){
    for (int i=1; i<=MAXH; i++){
        scanf("%s", &map[i][1]);
    }
}

typedef struct pixel
{
    int x, y;
} pixel;
pixel queue[MAXH*MAXW];
int wp, rp;
void enqueue(int x, int y)
{
    queue[wp].x = x;
    queue[wp++].y = y;
}
pixel dequeue() {return queue[rp++];}
int empty() {return wp==rp;}

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int BFS(int sx, int sy)
{
    wp = rp = 0;
    enqueue(sx, sy);
    // printf("enqueue %d %d\n", sx, sy);
    visited[sy][sx] = 1;
    pixel next;
    int x_next, y_next;
    int area = 1;
    while(!empty())
    {
        next = dequeue();
        // printf("dequeue %d %d\n", next.x, next.y);
        for (int i = 0; i < 4; i++)
        {
            x_next = next.x + dx[i]; y_next = next.y + dy[i];
            if (!(1 <= x_next && x_next <= MAXW && 1 <= y_next && y_next <= MAXH)) continue;
            if (map[sy][sx] == map[y_next][x_next] && visited[y_next][x_next] == 0)
            {
                enqueue(x_next, y_next);
                // printf("enqueue %d %d\n", x_next, y_next);
                visited[y_next][x_next] = 1;
                area++;
            }
        }
    }
    if (area < 4) return 0;   // 개수가 4보다 작으면 그냥 끝
    // printf("Boom\n");
    // 넘으면 해당 영역들 다 '.'으로 만들기
    wp = rp = 0;
    enqueue(sx, sy);
    visited[sy][sx] = 2;

    // printf("enqueue %d %d\n", sx, sy);
    while(!empty())
    {
        next = dequeue();
        // printf("dequeue %d %d\n", next.x, next.y);
        for (int i = 0; i < 4; i++)
        {
            x_next = next.x + dx[i]; y_next = next.y + dy[i];
            if (!(1 <= x_next && x_next <= MAXW && 1 <= y_next && y_next <= MAXH)) continue;
            // 이번에는 이미 방문한 영역들에 대해서만 바꾸기
            if (map[sy][sx] == map[y_next][x_next] && visited[y_next][x_next] == 1)
            {
                enqueue(x_next, y_next);
                visited[y_next][x_next] = 2;    // visited 는 2로
                // printf("enqueue %d %d\n", x_next, y_next);
                map[y_next][x_next] = '.';
            }
        }
    }    map[sy][sx] = '.';
    // printf("Boom Done\n");
    return 1;
}

// 체크 함수에서는 터지는 case가 있는지 체크
int check()
{
    int ok = 0;
    // visited 배열 초기화
    for (int yidx = 1; yidx <= MAXH; yidx++)
    {
        for (int xidx = 1; xidx <= MAXW; xidx++)
        {
            visited[yidx][xidx] = 0;
        }
    }
    // printf("visited clear\n");
    // 전 범위 탐색하면서 터질거 터뜨리기
    for (int yidx = 1; yidx <= MAXH; yidx++)
    {
        for (int xidx = 1; xidx <= MAXW; xidx++)
        {
            if (visited[yidx][xidx] == 0 && map[yidx][xidx] != '.') // 방문 안했고 색이 있을 때
            {
                // printf("BFS start at %d %d\n", xidx, yidx);
                if (BFS(xidx, yidx)) // 4면 해당 영역 다 '.'으로 만들기
                    ok = 1;
            }
        }
    }
    return ok;
}

int fall()
{
    // visited가 2이면서 map이 '.'인 영역들에 대해서 밑으로 내리기
    for (int xidx = 1; xidx <= MAXW; xidx++)
    {
        for (int yidx = 1; yidx <= MAXH; yidx++) // 위로는 끝까지 볼 필요 x
        {
            if (visited[yidx][xidx] == 2 && map[yidx][xidx] == '.')
            {
                // printf("Fall start at %d\n", yidx);
                for (int yfall = 1; yidx-yfall >= 1; yfall++)
                {
                    map[yidx-yfall+1][xidx] = map[yidx-yfall][xidx];
                }
                map[1][xidx] = '.';
            }
        }
    }
}

int solve()
{
    int cnt = 0;
    while(check()) // 터지는 동안 계속 수행
    {
        cnt++;
        fall();
        
        // debugging
        // for (int yidx = 1; yidx <= MAXH; yidx++)
        // {
        //     for (int xidx = 1; xidx <= MAXW; xidx++)
        //     {
        //         printf("%c", map[yidx][xidx]);
        //     }
        //     printf("\n");
        // }
    }
    return cnt;
}


int main(void){
    int T, t, ans = -1;
        InputData();//입력받는 부분

        //여기서부터 작성
        ans = solve();

        printf("%d\n", ans);//출력하는 부분
    return 0;
}