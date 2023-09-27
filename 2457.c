#include <stdio.h>
#include <stdlib.h>

int N;
int sm[100000+10];
int sd[100000+10];
int em[100000+10];
int ed[100000+10];
typedef struct flower
{
    int start, end;
} flower;
flower f[100000+10];
void InputData(void){
    scanf("%d", &N);
    for (int i=0; i<N; i++){
        scanf("%d %d %d %d", &sm[i], &sd[i], &em[i], &ed[i]);
        f[i].start = 100 * sm[i] + sd[i]; // 피는 날짜
        f[i].end = 100 * em[i] + ed[i];   // 지는 날짜
    }
}

int compare(const void* x, const void* y)
{
    flower* a = (flower*)x;
    flower* b = (flower*)y;
    if (a->start > b->start) return 1;
    else if (a->start == b->start) return 0;
    else return -1;
}

int solve()
{
    int count = 0;
    qsort(f, N, sizeof(flower), compare);

    int end = 301; // 종료 일자    
    int maxidx = -1;
    int lastidx = -1;
    int idx = 0;
    int bestend = 301;
    // printf("end:%d, nu[12]:%d, idx:%d\n", end, nu[12], idx);
    while(end < 1201 && idx < N)   // 가능한 조건에서 찾기
    {
        lastidx = maxidx;
        while(f[idx].start <= end && idx < N) // 찾고있거의 시작이 시작보다 작을때
        {
            if (end < f[idx].start) 
            {
                // printf("Impossible (end < f[idx].start)\n");
                break;    // 이건 안되는거
            }
            if (bestend < f[idx].end)  // 될 때
            {
                bestend = f[idx].end;
                maxidx = idx;
            }
            idx++;
        }
        if (lastidx == maxidx) return 0;
        end = bestend;
        count++;
    }
    if (end < 1201) return 0; // 불가능할 때
    return count; 
}

int main(void){
    int ans = -1;


    InputData();// 입력받는 부분
    ans = solve();
    
    

    printf("%d\n", ans);// 출력하는 부분
    return 0;
}