#include <stdio.h>

int main(void)
{
    int N = 0;
    scanf("%d", &N);
    int x = 0;
    int y = 0;
    int x_min = 100001;
    int x_max = 0;
    int y_min = 100001;
    int y_max = 0;
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &x, &y);
        if (N == 1)
        {
            printf("0");
            return 0;
        }
        if (i == 0)
        {
            x_min = x;
            y_min = y;
            x_max = x;
            y_max = y;
        }
        if (x <= x_min)
        {
            x_min = x;
        }
        else if (x >= x_max)
        {
            x_max = x;
        }
        if (y <= y_min)
        {
            y_min = y;
        }
        else if (y >= y_max)
        {
            y_max = y;
        }   
    }

    printf("%d\n", (x_max-x_min)*(y_max-y_min));
}