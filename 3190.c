#include <stdio.h>
#define MAXN (100)
int N;  // 격자의 크기
int K;  // 과일의 개수
int R[MAXN+10]; // 세로
int C[MAXN+10]; // 가로
int L;  // 이동 경로의 개수
int X[MAXN+10]; // X초 동안 그대로 움직임
char CMD[MAXN+10];  // L은 왼쪽, D는 오른쪽
int map[MAXN+10][MAXN+10];
typedef struct node
{
    int x, y;
    int dir;
} node;
node start;
node end;
node snake[MAXN*MAXN*10];
int head, tail;
int cmdp;
void InputData(void){
    scanf("%d", &N);
    scanf("%d", &K);
    for (int i=0; i<K; i++){
        scanf("%d %d", &R[i], &C[i]);
        map[R[i]][C[i]] = 2;    // 과일은 2
    }
    scanf("%d", &L);
    for (int i=0; i<L; i++){
        scanf("%d %c", &X[i], &CMD[i]);
    }
}

void printDebug(int t)
{
    printf("Current time:%d\n", t);
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            printf("%d", map[i][j]);
        }
        printf("\n");
    }
}

// dir 0으로 시작 (오른쪽) / 1이면 아래 / 2면 왼쪽 / 3이면 위
// L일 때 +1, R이면 -1
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int solve()
{
    // 시작 위치 초기화
    head = 1; tail = 1;
    snake[head].x = 1; snake[head].y = 1;
    map[snake[head].y][snake[head].x] = 1;
    int t = 0;
    int dir = 0;
    while (1)
    {
        if (t == X[cmdp]) // 현재 시각이 명령내리는 시각이라면 방향의 변화가 있어야됨
        {
            if (CMD[cmdp] == 'L')
            {
                dir = ((dir-1)+4)%4;
            }
            else if (CMD[cmdp] == 'D')
            {
                dir = (dir+1)%4;
            }
            cmdp++; // 명령 포인터 하나 증가
        }

        // 일단 움직이고 시간 하나 증가
        start.x = start.x + dx[dir]; start.y = start.y + dy[dir]; // Head가 이동, Head는 무조건 dir방향으로 이동.
        int nx = snake[head].x + dx[dir]; int ny = snake[head].y + dy[dir];
        if (!(1 <= nx && nx <= N && 1 <= ny && ny <= N)) // 벽에 부딪히면 끝
        {   
            t++;
            break; 
        }
        if (map[ny][nx] == 1) // 자기 몸 먹으면 끝
        {
            t++; break;
        }

        // 일단 몸 증가
        snake[head+1].x = nx;
        snake[head+1].y = ny;
        head++;
        if (map[ny][nx] == 0) // 과일이면 할일 없음, 땅이면 테일 증가
        {
            map[snake[tail].y][snake[tail].x] = 0;
            tail++;
        }
        map[ny][nx] = 1;
        t++;
        // printDebug(t);
    }
    return t;
}

int main(void){
    int ans = -1;

    InputData();//입력받는 부분

    ans = solve();

    printf("%d\n", ans);//출력하는 부분
    return 0;
}