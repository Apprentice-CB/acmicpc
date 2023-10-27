#include <stdio.h>

int T, a, b;

int main(void)
{
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%d %d", &a, &b);
        int c = a;
        for (int j = 1; j < b; j++)
        {
            c = c * a % 10;
        }
        if (c % 10 == 0) printf("10\n");
        else printf("%d\n", c % 10);
    }
}
