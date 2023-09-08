#include <stdio.h>
#include <string.h>

int N, K;
char name[300000+10][22];

int rp[22], wp[22];
int q[22][300000];

void push(int len, int n)
{
    q[len][wp[len]++] = n;
}
int top(int len)
{
    return q[len][rp[len]];
}
void pop(int len)
{
    rp[len]++;
}
int size(int len)
{
    return wp[len] - rp[len];
}
int empty(int len)
{
    return wp[len] == rp[len];
}


void getInput()
{
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++)
    {
        scanf("%s", name[i]);
    }
}

int main(void)
{
    getInput();

    long long ans = 0;
    int len;
    for (int i = 0; i < N; i++)
    {
        len = strlen(name[i]);
        while (!empty(len) &&  i - top(len) > K)
        {
            // printf("pop %d at len %d\n", top(len), len);
            pop(len);
        }
        // printf("push %d at len %d\n", i, len);
        ans += size(len);
        push(len, i);
    }
    printf("%lld", ans);
}