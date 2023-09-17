#include <stdio.h>

int N, K;
int visited[100000+10];
typedef struct node
{
    int p, t;
} node;
node queue[100000+10];
int wp, rp;
void enqueue(int p, int t)
{
    queue[wp].p = p;
    queue[wp++].t = t;
}
node dequeue() {return queue[rp++];}
int empty() {return wp==rp;}

int BFS(int n)
{
    enqueue(n, 0);
    visited[n] = 1;
    node prev;
    while(!empty())
    {
        prev = dequeue();
        if (prev.p == K) return prev.t;
        if (0 <= prev.p-1 && prev.p-1 <= 100000)
        {
        if (visited[prev.p-1] == 0)
        {
            visited[prev.p-1] = 1;
            enqueue(prev.p-1, prev.t+1);
        }
        }
        if (0 <= prev.p+1 && prev.p+1 <= 100000)
        {
        if (visited[prev.p+1] == 0)
        {
            visited[prev.p+1] = 1;
            enqueue(prev.p+1, prev.t+1);
        }
        }
        if (0 <= prev.p && prev.p*2 <= 100000)
        {
        if (visited[prev.p*2] == 0)
        {
            visited[prev.p*2] = 1;
            enqueue(prev.p*2, prev.t+1);
        }
        }
    }
    return -1;
}

int main(void)
{
    scanf("%d %d", &N, &K);
    int cnt = BFS(N);
    printf("%d", cnt);
}