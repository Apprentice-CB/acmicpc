#include <stdio.h>

int main(void)
{
    int t = 0;
    int n = 0;
    int s = 0;
    int p = 0;
    int q = 0;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &s);
        scanf("%d", &n);
        for (int j = 0; j < n; j++)
        {
            scanf("%d %d", &q, &p);
            s += q*p;
        }
        printf("%d\n", s);
    }
}   