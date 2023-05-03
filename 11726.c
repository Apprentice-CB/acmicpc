#include <stdio.h>

int main(void)
{
    int n = 0;
    scanf("%d", &n);
    int arr[1001] = {0, };
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 2;
    for (int i = 2; i <= n; i++)
    {
        arr[i] = (arr[i-1] + arr[i-2]) % 10007;
    }
    printf("%d", arr[n]);
}