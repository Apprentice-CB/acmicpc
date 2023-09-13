#include <stdio.h>

int N, M;
int map[110][110];
int list[110];

typedef struct node
{
    int n, cnt;
} node;
node queue[100*100+10];
int wp, rp;

void enqueue(int n, int cnt) 
{
    queue[wp].cnt = cnt;
    queue[wp++].n = n;
}
node dequeue() {return queue[rp++];}
int empty() {return wp==rp;}

void getInput()
{
    int a, b;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &a, &b);
        map[a][b] = 1;
        map[b][a] = 1;
    }
}

int BFS(int s)
{
    int visited[110];
    for (int i = 1; i <= N; i++)
    {
        visited[i] = 1<<30;
    } 
    enqueue(s, 0);
    // printf("enqueue %d, 0\n", s);
    visited[s] = 0;

    node next;
    while(!empty())
    {
        next = dequeue();
        // printf("dequeue %d %d\n", next.n, next.cnt);

        for (int i = 1; i <= N; i++)
        {
            if (map[next.n][i] == 1)    // 연결되어 있으면
            {
                if (visited[i] > visited[next.n] + map[next.n][i])
                {
                    enqueue(i, next.cnt+1);
                    visited[i] = visited[next.n] + map[next.n][i];
                    // printf("enqueue %d %d\n", i, next.cnt+1);
                }
            }
        }
    }
    int sum = 0;
    for (int i = 1; i <= N; i++)
    {
        // printf("visited %d:%d \n", i, visited[i] );
        if (visited[i] != 1<<30) 
        {
            sum += visited[i];
        }
    }
    return sum;
}

int main(void)
{
    getInput();

    int min = 10000;
    int kb;
    int ans = -1;
    for (int i = 1; i <= N; i++)
    {
        kb = BFS(i);
        // printf("%d\n", kb);
        if (kb < min)
        {
            min = kb;
            ans = i;
        }
    }
    printf("%d", ans);
}