#include <stdio.h>

int C, R, K;
int X, Y;
int map[1001][1001] = {0, };
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int cur_x;
int cur_y;
int num;
int i;

void InputData(void) {
	scanf("%d %d", &C, &R);
	scanf("%d", &K);
}
void OutputData(void) {
	if (X == 0) printf("0\n");
	else printf("%d %d\n", X, Y);
}
int main(void)
{
	// 입력받는 부분
	InputData();
    if (C*R < K)
    {
        printf("0");
        return 0;
    }

	// 여기서부터 작성
    num = 1;
    X = Y = 1;
    i = 0;
    int turn_to_x = 0;
    int turn_to_y = 0;
    int turn = 0;
    while (1)
    {
        if (num == K) break;
        map[Y][X] = num;
        num++;
        if ((X + dx[i]) < 1 || (X + dx[i]) > C || (Y + dy[i]) < 1 || (Y + dy[i]) > R || (map[Y+dy[i]][X+dx[i]] != 0)) {
            i++;
            i = i % 4;
            
        }
        X = X + dx[i];
        Y = Y + dy[i];
    }

    for (int ridx = 1; ridx <= R; ridx++)
    {
        for (int cidx = 1; cidx <= C; cidx++)
        {
            printf("%d\t", map[ridx][cidx]);
        }
        printf("\n");
    }
	// 출력하는 부분
	OutputData();
	return 0;
}