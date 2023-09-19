#include <stdio.h>
#define MAXH (5)
#define MAXW (9)
char map[MAXH+2][MAXW+2];
int solremain, solmove;
void InputData(void){
    for (int h=1; h<=MAXH; h++){
        scanf("%s", &map[h][1]);
    }
}

void CopyMap(char src[][MAXW+2], char dst[][MAXW+2])
{
    for (int h = 1; h <= MAXH; h++)
    {
        for (int w = 1; w <= MAXW; w++)
        {
            dst[h][w] = src[h][w];
        }
    }
}

int dw[4] = {-1, 1, 0, 0};
int dh[4] = {0, 0, 1, -1};

int checkTodo(char nextmap[][MAXW+2], int move)
{
    // printf("move:%d\n");
    int nw, nh, nnw, nnh;
    for (int h = 1; h <= MAXH; h++)
    {
        for (int w = 1; w <= MAXW; w++)
        {
            if (nextmap[h][w] == 'o')   // 핀일 때
            {
                // 나머지 사방을 탐색해서, 인접한 것도 핀이면서 동시에 그 다음칸이 비어있는 경우 탐색
                for (int dir = 0; dir < 4; dir++)
                {
                    nw = w + dw[dir]; nh = h + dh[dir];
                    if (!(1 <= nw && nw <= MAXW && 1 <= nh <= nh <= MAXH)) continue; // 다음칸이 지도를 벗어나면 쫑
                    nnw = nw + dw[dir]; nnh = nh + dh[dir];
                    if (!(1 <= nnw && nnw <= MAXW && 1 <= nnh && nnh <= MAXH)) continue; // 다다음 칸도 지도 안에 있어야됨
                    if (nextmap[nh][nw] == 'o' && nextmap[nnh][nnw] == '.') // 인접 칸이 핀이고, 그 다음칸이 빈칸일 경우에만 잡아먹어야지
                    {
                        return 1; // 할게 있음
                    }
                }  
            }
        }
    }
    // printf("Nothing to do\n");
    return 0; // 할게 없음
}

void PrintMap(char tempmap[][MAXW+2], int move)
{
    printf("move:%d\n", move);
    for (int h = 1; h <= MAXH; h++)
    {
        for (int w = 1; w <= MAXW; w++)
        {
            printf("%c", tempmap[h][w]);
        }
        printf("\n");
    }
    printf("\n");
}

void DFS(int move, char nextmap[][MAXW+2]) // 움직인 횟수, DFS 들어왔을 때 사용할 지도
{
    // if (move > solmove) return; // 가지치기는 애매하니까 일단 pass
    char tempmap[MAXH+2][MAXW+2]; // 이 DFS에서 사용할 임시 맵 선언
    CopyMap(nextmap, tempmap);    // 기존 depth에서 쓰던 map을 임시 맵으로 가져오기
    if (!checkTodo(tempmap, move)) // 종료 조건, 더 이상 할게 없다면
    {

        int remainpin = 0;
        for (int h = 1; h <= MAXH; h++)
        {
            for (int w = 1; w <= MAXW; w++)
            {
                if (tempmap[h][w] == 'o') remainpin++;
            }
        }
        if (remainpin < solremain) 
        {

            solremain = remainpin;
            solmove = move;
            // printf("solremain updated:%d, solmove:%d\n", solremain, solmove);
        }
        else if (remainpin == solremain)
        {
            if (solmove > move) solmove = move;
        }
        return;
    }

    int nw, nh, nnw, nnh;
    // 임시 맵을 탐색하면서 핀인 경우를 탐색
    for (int h = 1; h <= MAXH; h++)
    {
        for (int w = 1; w <= MAXW; w++)
        {
            if (tempmap[h][w] == 'o')   // 핀일 때
            {
                // 나머지 사방을 탐색해서, 인접한 것도 핀이면서 동시에 그 다음칸이 비어있는 경우 탐색
                for (int dir = 0; dir < 4; dir++)
                {
                    nw = w + dw[dir]; nh = h + dh[dir];
                    if (!(1 <= nw && nw <= MAXW && 1 <= nh <= nh <= MAXH)) continue; // 다음칸이 지도를 벗어나면 쫑
                    nnw = nw + dw[dir]; nnh = nh + dh[dir];
                    if (!(1 <= nnw && nnw <= MAXW && 1 <= nnh && nnh <= MAXH)) continue; // 다다음 칸도 지도 안에 있어야됨
                    if (tempmap[nh][nw] == 'o' && tempmap[nnh][nnw] == '.') // 인접 칸이 핀이고, 그 다음칸이 빈칸일 경우에만 잡아먹어야지
                    {
                        tempmap[h][w] = '.';
                        tempmap[nh][nw] = '.'; tempmap[nnh][nnw] = 'o';
                        // PrintMap(tempmap, move+1);
                        DFS(move+1, tempmap);   // 그 다음 DFS로 들어가기
                        tempmap[h][w] = 'o';
                        tempmap[nh][nw] = 'o'; tempmap[nnh][nnw] = '.';
                    }
                }  
            }
        }
    }
}


int main(void){
    int T;
    int ans;
    scanf("%d", &T);
    for (int t=1; t<=T; t++)
    {
        InputData();//입력받는 부분

        solmove = 1<<29;
        solremain = 1<<29;
        DFS(0, map);

        printf("%d %d\n", solremain, solmove);//출력하는 부분
    }
    return 0;
}