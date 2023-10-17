#include <stdio.h>

int F, S, G, U, D;
typedef struct floor
{
    int n, t;
} floor;
floor queue[1000000+10];
int wp, rp;
void enqueue(int n, int t)
{
    queue[wp].n = n;
    queue[wp++].t = t;
}
floor dequeue() {return queue[rp++];}
int empty() {return wp==rp;}

int visited[1000000+10];

void getInput()
{
    scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
}

int BFS()
{
    if (S == G) return 0;
    wp=rp=0;
    enqueue(S, 0);
    visited[S] = 1;
    floor next;
    while(!empty())
    {
        next = dequeue();
        if (1 <= next.n + U && next.n + U <= F && visited[next.n+U] == 0)
        {
            if (next.n + U == G) return next.t+1;
            enqueue(next.n + U, next.t + 1);
            visited[next.n + U] = 1;
        }
        if (1 <= next.n - D && next.n - D <= F && visited[next.n-D] == 0)
        {
            if (next.n - D == G) return next.t+1;
            enqueue(next.n - D, next.t + 1);
            visited[next.n - D] = 1;
        }
    }
    return -1;
}

int main(void)
{
    getInput();
    int ans = BFS();
    if (ans == -1) printf("use the stairs\n");
    else printf("%d\n", ans);
    return 0;
}