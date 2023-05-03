#include <stdio.h>

int main(void)
{
    int n = 0;
    scanf("%d", &n);
    int arr[1001] = {0, };
    arr[1] = 1;
    arr[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        arr[i] = arr[i-1] + arr[i-2];
    }
    printf("%d", arr[n]%10007);
}