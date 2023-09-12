#include <stdio.h>
#define MAXN (100)
int L;//정비를 받지 않고 갈수있는 최대거리
int N;//정비소 개수
int dist[MAXN+10];//정비소사이거리
int time[MAXN+10];//정비시간
int weight[MAXN+10]; // 
int path[MAXN+10];
int cnt;

typedef struct node
{
    int N;  // 정비소
    int t;  // 시간
} node;
node queue[MAXN*MAXN+10];
int wp, rp;
void enqueue(int N, int t)
{
    queue[wp].N = N;
    queue[wp++].t = t;
}
node dequeue() {return queue[rp++];}
int empty() {return wp==rp;}

void InputData(void){
    scanf("%d", &L);
    scanf("%d", &N);
    for (int i=1; i<=N+1; i++){
        scanf("%d", &dist[i]);
    }
    for (int i=1; i<=N; i++){
        scanf("%d", &time[i]);
    }
}

void BFS()
{
    // 가중치 초기화
    for (int i = 1; i <= N+1; i++)
    {
        weight[i] = 1<<30;
    }
    // 첫 방문할 정비소들
    int d = 0;
    for (int i = 1; i <= N+1; i++)
    {
        d += dist[i];
        if (d <= L)
        {
            enqueue(i, time[i]);
            weight[i] = time[i];
            path[i] = 0;
            // printf("enqueue %d %d\n", i, time[i]);
        }
        else break;
    }

    node temp;
    int tempDist;
    while (!empty())
    {
        temp = dequeue();
        // printf("dequeue %d %d\n", temp.N, temp.t);
        tempDist = 0;
        for (int i = temp.N+1; i <= N+1; i++) // 모든 경우에 대해 탐색
        {
            tempDist += dist[i];
            if (tempDist <= L) // 이동 가능한 거리면
            {
                if (weight[i] > weight[temp.N] + time[i])
                {
                    enqueue(i, time[i]);
                    // printf("enqueue %d %d\n", i, time[i]);
                    weight[i] = weight[temp.N] + time[i];
                    path[i] = temp.N;
                }    
            }
            else break;
        }
    }
}

void showPath(int n)
{
    if (n > 0)
    {
        showPath(path[n]);
        printf("%d ", n);
    }
}

void getPath(int n)
{
    if (n > 0)
    {
        getPath(path[n]); cnt++;
    }
}

int main(void){
    InputData();//입력 받는 부분

    //여기서부터 작성
    BFS();
    // printf("%d\n", weight[N]);

    getPath(path[N+1]);
    printf("%d\n%d\n", weight[N+1], cnt);
    showPath(path[N+1]);
    // printf("\n");
    // for (int i = 1; i <= N+1; i++)
    // {
    //     printf("%d ", path[i]);
    // }

    return 0;
}