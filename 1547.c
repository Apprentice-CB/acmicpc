#include <stdio.h>

int main(void)
{
    int M = 0;
    scanf("%d", &M);
    int x = 0;
    int y = 0;
    int ball = 1;
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &x, &y);
        if (ball == x)
        {
            ball = y;
        }
        else if (ball == y)
        {
            ball = x;
        }
    }
    printf("%d", ball);
}