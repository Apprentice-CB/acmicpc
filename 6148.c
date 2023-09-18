#include <stdio.h>
#define MAXN (20)
int N, B;
int H[MAXN+10];
int used[MAXN+10];
int min_cnt;
void InputData(void){
    scanf("%d %d", &N, &B);
    for (int i=0; i<N; i++){
        scanf("%d", &H[i]);
    }
}

void DFS(int sum, int depth)
{
    sum += H[depth];
    if (sum >= min_cnt) 
    {
        // printf("DFS done due to over\n");
        return; // 가지치기
    }
    if (sum >= B)
    {
        if (sum < min_cnt)
        {
            min_cnt = sum;
            // printf("DFS done at sum=%d\n", sum);
        }
        return;
    }
    if (depth >= N) 
    {
        // printf("DFS impossible\n");
        return; // 종료조건
    }

    for (int i = depth+1; i < N; i++)
    {
        // printf("Go into DFS(%d, %d)\n", sum, i);
        DFS(sum, i);
    }
}

int solve()
{
    min_cnt = 1<<30;
    for (int i = 0; i < N; i++)
    {
        // printf("DFS Start (0, %d)\n", i);
        DFS(0, i);
    }
    
    min_cnt = min_cnt - B;
    return min_cnt;
}

int main(void){
    int T, ans = -1;
    scanf("%d", &T);
    for (int t=1; t<=T; t++){
        InputData();//입력받는 부분

        //여기서부터 작성
        ans = solve();

        printf("%d\n", ans);
    }
    return 0;
}
