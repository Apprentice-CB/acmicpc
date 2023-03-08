#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int N = 0;
    int cnt = 665;
    int idx = 0;
    int divider = 0;
    scanf("%d", &N);
    while (1)
    {
        if (idx == N)
        {
            break;
        }
        cnt++;
        divider = cnt;
        while (divider >= 666)
        {
            if (divider % 1000 == 666)
            {
                idx++;
                break;
            }
            else
            {
                divider = divider / 10;
            }
        }
    }
    printf("%d", cnt);

    return 0;
}