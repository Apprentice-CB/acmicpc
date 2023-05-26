#include <stdio.h>

int main(void)
{
    int N = 0;
    int m = 0;
    int M = 0;
    int T = 0;
    int R = 0;
    scanf("%d %d %d %d %d", &N, &m, &M, &T, &R);
    int cur = m;
    int cnt = 0;
    int t = 0;
    while (cnt != N)
    {
        if (cur + T > M && cur - R < m)
        {
            t = 0;
            break;
        }
        if (cur + T <= M)
        {
            cur = cur + T;
            cnt++;
        }
        else if (cur + T > M)
        {
            if (cur - R < m)
            {
                cur = m;
                t++;
            }
            else if (cur - R >= m)
            {
                cur = cur - R;
                t++;
            }
        }

    }
    if (t == 0) t = -1;
    else
    {
        t += N;
    }
    printf("%d", t);
}