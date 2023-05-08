#include <stdio.h>

int main(void)
{
    int T = 0;
    int N = 0;
    int M = 0;
    int a = 0;
    int b = 0;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%d %d", &N, &M);
        for (int j = 0; j < M; j++)
        {
            scanf("%d %d", &a, &b);
        }
        printf("%d\n", N-1);
    }
    
}