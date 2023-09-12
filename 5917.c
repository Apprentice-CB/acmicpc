#include <stdio.h>

int N, M;
int A[10000 + 10];
int B[10000 + 10];
int L[10000 + 10];
int map[110][110];
void InputData(void){
    scanf("%d %d", &N, &M);
    for (int i = 0; i<M; i++){
        scanf("%d %d %d", &A[i], &B[i], &L[i]);
        map[A[i]][B[i]] = L[i];
        map[B[i]][A[i]] = L[i];
    }
}
int dist[110];

int queue[100000];
int wp, rp;
void enqueue(int i) { queue[wp++] = i; }
int empty() {return wp==rp;}
int dequeue() {return queue[rp++];}

void BFS()
{
    rp = wp = 0;
    for (int i = 1; i <= N; i++)
    {
        dist[i] = 1<<30;
    }
    enqueue(1);
    // printf("enqueue 1, wp:%d rp:%d\n", wp, rp);
    dist[1] = 0;

    int next;
    while (!empty())
    {
        next = dequeue();
        // printf("dequeue %d, wp:%d, rp:%d\n", next, wp, rp);
        for (int i = 1; i <= N; i++)
        {
            if (map[next][i] != 0)
            {
                if (dist[i] > dist[next] + map[next][i])
                {
                    enqueue(i);
                    dist[i] = dist[next] + map[next][i];
                    // printf("enqueue %d, wp:%d, rp:%d\n", i, wp, rp);
                }
            }
        }
    }
}


int main(void){
    int ans = 0;

    InputData();// 입력받는 부분

    // 여기서부터 작성
    int min_dist;
    BFS();
    min_dist = dist[N];
    
    int temp_dist;
    for (int i = 0; i < M; i++)
    {
        // 한 경로의 길이 2배 & 업데이트
        L[i] = L[i] * 2;
        map[A[i]][B[i]] = L[i];
        map[B[i]][A[i]] = L[i];        
        BFS(); temp_dist = dist[N];
        // printf("temp_dist:%d\n", temp_dist);
        if (ans < temp_dist - min_dist)
        {
            ans = temp_dist - min_dist;
            // printf("i:%d, temp_dist:%d, ans:%d\n",i, temp_dist, ans);
        }
        // 그 경로 반띵 & 업데이트
        L[i] = L[i] / 2;
        map[A[i]][B[i]] = L[i];
        map[B[i]][A[i]] = L[i];
    }


    printf("%d\n", ans);// 출력하는 부분
    return 0;
}