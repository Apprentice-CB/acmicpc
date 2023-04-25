#include <stdio.h>

int fibo1(int n, int* cnt)
{
    int a = *cnt;
    if (n == 1 || n == 2)
    {
        a++;
        return a;
    }
    else
    {
        return fibo1(n-1, cnt) + fibo1(n-2, cnt);
    }
}

int fibo2(int n)
{
    int arr[41] = {0, };
    arr[1] = 1;
    arr[2] = 1;
    int cnt = 0;
    for (int i = 3; i <= n; i++)
    {   
        cnt++;
        arr[i] = arr[i-1] + arr[i-2];
    }
    return cnt;
}

int main(void)
{
    int n = 0;
    scanf("%d", &n);
    int cnt1 = 0;
    int cnt2 = 0;
    int arr[41] = {0, };
    printf("%d\n%d", fibo1(n, &cnt1), fibo2(n));
}