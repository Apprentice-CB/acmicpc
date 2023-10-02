#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int T;
int S, E;

int prime[10000];

typedef struct node
{
    int n, t;
} node;
node queue[10000];
int wp, rp;
int visited[10000];
void enqueue(int n, int t)
{
    queue[wp].n = n;
    queue[wp++].t = t;
}
node dequeue() {return queue[rp++];}
int empty() {return wp==rp;}

void getInput()
{
    scanf("%d %d", &S, &E);
}

int checkDigit(int a, int b)
{
    int cnt = 0;
    while (a > 0 && b > 0)
    {
        if (a % 10 != b % 10) cnt++;
        a = a / 10;
        b = b / 10;
    }
    if (cnt == 1) return 1;
    return 0;
}

int BFS()
{
    for (int i = 1000; i < 10000; i++)
    {
        visited[i] = 0;
    }
    wp = rp = 0;
    enqueue(S, 0);
    // printf("enqueue %d 0\n", S);
    visited[S] = 1;

    if (S == E) return 0;

    node next;
    while(!empty())
    {
        next = dequeue();
        // printf("dequeue %d %d\n", next.n, next.t);
        for (int i = 1000; i < 10000; i++)
        {
            // 방문 안했고, prime이면서, 한자리 차이날 때
            if (visited[i] == 0 && prime[i] == 0 && checkDigit(next.n, i))
            {
                visited[i] = 1;
                enqueue(i, next.t+1);
                // printf("enqueue %d %d\n", i, next.t+1);
                if (i == E) return next.t+1;
            }
        }
    }
    return -1;
}

void era()
{
    for (int i = 2; i < 10000; i++)
    {
        if (prime[i] == 1) continue;
        for (int j = 2*i; j < 10000; j += i)
        {
            prime[j] = 1;
        }
    }
}

int main(void)
{
    int ans = -1;
    scanf("%d", &T);
    era();
    for (int i = 0; i < T; i++)
    {
        getInput();
        ans = BFS();
        if (ans == -1)
        {
            printf("Impossible\n");
        }
        else
        {
            printf("%d\n", ans);
        }
    }
    return 0;
}