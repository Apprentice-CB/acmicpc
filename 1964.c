#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N = 0;
    scanf("%d", &N);
    long long* arr = (long long*)malloc(sizeof(long long) * (N+1));
    arr[1] = 5;
    for (int i = 2; i <= N; i++)
    {
        arr[i] = arr[i-1] + 3*i + 1;
    }
    printf("%lld", arr[N] % 45678);  
}