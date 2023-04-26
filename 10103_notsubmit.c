#include <stdio.h>

int main(void)
{
    int n = 0;
    scanf("%d", &n);
    int c = 0;
    int s = 0;
    int c_res = 100;
    int s_res = 100;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &c, &s);
        if (c > s)
        {
            s_res -= c;
        }
        else if (c < s)
        {
            c_res -= s;
        }
        else
        {
            continue;
        }
    }
    printf("%d\n%d", c_res, s_res);
}