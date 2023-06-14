#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n = 0;
    scanf("%d", &n);
    int* arr = (int*)malloc(sizeof(int)*n);
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            sum += (arr[i] - arr[j]) * (arr[i] - arr[j]);
        }
    }
    printf("%lld", sum);
}