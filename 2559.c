#include <stdio.h>

int arr[100000+10];
int N, K;

int main(void)
{
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    int s = 0;
    int e = K-1;
    int sum = 0;
    int max = 0;
    for (int i = 0; i < K; i++)
    {
        sum += arr[i];
    }
    max = sum;
    printf("%d %d\n",e, sum);
    while(e < N-1)
    {
        sum -= arr[s++];
        sum += arr[++e];
        printf("%d %d\n",e, sum);
        if (max < sum) max = sum;
    }
    printf("%d\n", max);
    return 0;
}