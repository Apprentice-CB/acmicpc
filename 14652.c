#include <stdio.h>

int main(void)
{
    int M = 0;
    int N = 0;
    int m = 0;
    int n = 0;
    int K = 0;
    scanf("%d %d %d", &N, &M, &K);
    printf("%d %d", K / M, K % M);
}