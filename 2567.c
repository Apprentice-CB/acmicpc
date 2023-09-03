#include <stdio.h>

int N;
int A[100+10];
int B[100+10];
int map[101][101];
void InputData(void){
    scanf("%d", &N);
    for (int i=0; i<N; i++){
        scanf("%d %d", &A[i], &B[i]);
    }
}

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(void){
    int ans = 0;

    InputData();// 입력받는 부분

    int len = 0;
    int x, y;
    for (int i = 0; i < N; i++)
    {
        for (int xidx = A[i]; xidx < A[i]+10; xidx++)
        {
            for (int yidx = B[i]; yidx < B[i]+10; yidx++)
            {
                map[yidx][xidx] = 1;    // 색종이 영역은 1
            }
        }
    }

    int x_next, y_next;
    for (int yidx = 0; yidx < 101; yidx++)
    {
        for (int xidx = 0; xidx < 101; xidx++)
        {
            if (map[yidx][xidx] == 1) {
                for (int i = 0; i < 4; i++)         
                {
                    x_next = xidx + dx[i];
                    y_next = yidx + dy[i];
                    if (0 <= x_next && x_next < 101 && 0 <= y_next && y_next < 101)
                    {
                        if (map[y_next][x_next] == 0)   
                        {
                            ans++;
                        }
                    }
                }
            }
        }
    }

    printf("%d\n", ans);// 출력하는 부분
    return 0;
}