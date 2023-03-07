#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int N = 0;
    int K = 0;
    scanf("%d %d", &N, &K);
    int *arr = (int*)malloc(sizeof(int) * N);
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", arr+i);
    }
    int i = N-1;
    while(K > 0)
    {
        while ((K / arr[i]) > 0)
        {
            K = K - arr[i];
            cnt++;
        }
        i--;
    }
    printf("%d", cnt);
}