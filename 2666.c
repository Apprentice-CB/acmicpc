#include <stdio.h>
#define MAXN (20)

int N;
int sl, sr;
int M;
int seq[MAXN+10];
int min_cnt = 1<<29;

void InputData(void){
    scanf("%d", &N);
    scanf("%d %d", &sl, &sr);
    scanf("%d", &M);
    for (int i=0; i<M; i++){
        scanf("%d", &seq[i]);
    }
}

int absi(int a)
{
    if (a > 0) return a;
    return -a;
}

void DFS(int left, int right, int depth, int cnt)
{
    if (depth >= M) // 종료 조건
    {
        if (cnt < min_cnt) min_cnt = cnt;
        // printf("Done DFS at cnt:%d min_cnt:%d\n", cnt, min_cnt);
        return;
    }

    if (seq[depth] <= left)
    {
        cnt += absi(left - seq[depth]);
        // printf("Only Left, Go into DFS(%d, %d, %d, %d)\n", seq[i], right, depth+1, cnt);
        DFS(seq[depth], right, depth+1, cnt);
        cnt -= absi(left - seq[depth]);      
    }
    else if (left < seq[depth] && seq[depth] < right)
    {
        // 왼쪽 case
        cnt += absi(left - seq[depth]);
        // printf("Left Go into DFS(%d, %d, %d, %d)\n", seq[i], right, depth+1, cnt);
        DFS(seq[depth], right, depth+1, cnt);
        cnt -= absi(left - seq[depth]);
        // 오른쪽 case
        cnt += absi(right - seq[depth]);
        // printf("Right Go into DFS(%d, %d, %d, %d) at i:%d\n", left, seq[i], depth+1, cnt, i);
        DFS(left, seq[depth], depth+1, cnt);
        cnt -= absi(right - seq[depth]);
    }
    else if (seq[depth] >= right)    // Only right
    {
        cnt += absi(right - seq[depth]);
        // printf("Only right, Go into DFS(%d, %d, %d, %d) at i:%d\n", left, seq[i], depth+1, cnt, i);
        DFS(left, seq[depth], depth+1, cnt);
        cnt -= absi(right - seq[depth]);
    }
    return;            
}


int solve()
{
    // printf("Start DFS left:%d, right:%d\n", sl, sr);
    DFS(sl, sr, 0, 0);

    return min_cnt;
}

int main(void){
    int ans = -1;

    InputData();//입력받는 부분

    //여기서부터 작성
    ans = solve();

    printf("%d\n", ans);//출력하는 부분
    return 0;
}