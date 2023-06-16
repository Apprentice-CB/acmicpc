#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int ar[301][301] = {0, };
    int N = 0;
    int M = 0;
    scanf("%d %d", &N, &M);
    for (int nidx = 0; nidx < N; nidx++)
    {
        for (int midx = 0; midx < M; midx++)
        {
            scanf("%d", &ar[nidx][midx]);
        }
    }
    int K = 0;
    scanf("%d", &K);
    int i = 0;
    int j = 0;
    int x = 0;
    int y = 0;
    int sum = 0;
    for (int kidx = 0; kidx < K; kidx++)
    {
        scanf("%d %d %d %d", &i, &j, &x, &y);
        for (int a = i-1; a < x; a++)
        {
            for (int b = j-1; b < y; b++)
            {
                sum += ar[a][b];
            }
        }
        printf("%d\n", sum);
        sum = 0;
    }
}