#include <stdio.h>

int main(void)
{
    int N = 0;
    int arr[5];
    scanf("%d", &N);
    scanf("%d %d %d %d %d", arr, arr+1, arr+2, arr+3, arr+4);
    N = N % 10;
    int cnt = 0;
    for (int i = 0; i < 5; i++)
    {
        if (N == arr[i])
        {
            cnt++;
        }
    }
    printf("%d", cnt);
}