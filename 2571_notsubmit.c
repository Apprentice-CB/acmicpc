#include <stdio.h>
#include <string.h>

int N;//색종이 수
int X[100+10];
int Y[100+10];
int map[110][110];

typedef struct corner
{
    int x;
    int y;
} corner;

corner C[410];
int nC = 0;

void InputData(void) {
    scanf("%d", &N);
    for (int i=0; i<N; i++){
        scanf("%d %d", &X[i], &Y[i]);
    }
}

void FillMap(void)
{
    for (int i = 0; i < N; i++)
    {
        for (int yidx = Y[i]; yidx < Y[i] + 10; yidx++)
        {
            for (int xidx = X[i]; xidx < X[i] + 10; xidx++)
            {
                map[yidx][xidx] = 1;
            }
        }
    }
    for (int xidx = 0; xidx < 100; xidx++)
    {
        int cnt = 1;
        for (int yidx = 0; yidx < 100; yidx++)  // 세로기준 높이
        {
            if (map[yidx][xidx] == 1)
            {
                map[yidx][xidx] = cnt++;
            }
            else if (map[yidx][xidx] == 0)
            {
                cnt = 1;
            }
        }
    }
}

int min(int a, int b)
{
    if (a > b) 
    {
        return b;
    }
    return a;
}


int CheckBox()
{
    int ans = 0;
    int max = 0;
    int h = 100;
    for (int yidx = 0; yidx < 100; yidx++)  // 세로기준 높이
    {
        for (int xidx = 0; xidx < 100; xidx++) // 가로 고정 위치에 대한 iter
        {
            if (map[yidx][xidx] == 0) continue;    // 가로 고정 위치가 0이 아니면 가로한칸 이동
            int height =100 ;
            for (int k = xidx; k < 100; k++)
            {
                if (map[yidx][k] == 0) break;   // 고정한 위치 기준 탐색하다가 0이면 여기서 끝
                height = min(height, map[yidx][k]);
                ans = height * (k-xidx+1);
                if (ans > max) max = ans;
            }
        }
    }
    return max;
}

int main(void) {
    int ans = 0;
    InputData();//입력받는 부분
    
    //여기서부터 작성
    FillMap();

    // for (int yidx = 0; yidx < 25; yidx++)
    // {
    //     for (int xidx = 0; xidx < 26; xidx++)
    //     {
    //         printf("%d\t", map[yidx][xidx]);
    //     }
    //     printf("\n");
    // }

    int square = 0;
    int maxs = CheckBox();
    
    
    printf("%d\n", maxs);//출력하는 부분
    return 0;
}