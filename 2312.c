#include <stdio.h>
#include <string.h>

int main(void)
{
    int N = 0;
    scanf("%d", &N);
    int a = 0;
    int i = 0;
    int arr[100001] = {0, };
    for (int ni = 0; ni < N; ni++)
    {
        scanf("%d", &a);
        i = 2;
        while(1)
        {
            if (a == 1)
            {
                break;
            }
            if (a % i == 0)
            {
                a = a / i;
                arr[i]++;
            }
            else
            {
                i++;
            }
        }
        for (int j = 1; j <= 100000; j++)
        {
            if (arr[j] != 0)
            {
                printf("%d %d\n", j, arr[j]);
                arr[j] = 0;
            }
        }
    }
}