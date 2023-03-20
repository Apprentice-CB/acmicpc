#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int x1 = 0;
    int x2 = 0;
    int y1 = 0;
    int y2 = 0;
    scanf("%d %d", &x1, &y1);
    scanf("%d %d", &x2, &y2);
    if (x1 == x2 )
    {
        int y_temp = 0;
        scanf("%d %d", &x2, &y_temp);
        if (y_temp == y1)
        {
            printf("%d %d", x2, y2);
        }
        else
        {
            printf("%d %d", x2, y1);
        }
    }
    else if (y1 == y2)
    {
        int x_temp = 0;
        scanf("%d %d", &x_temp, &y2);
        if (x_temp == x1)
        {
            printf("%d %d", x2, y2);
        }
        else
        {
            printf("%d %d", x1, y2);
        }
    }
    else
    {
        int x_temp = 0;
        int y_temp = 0;
        scanf("%d %d", &x_temp, &y_temp);
        if (x_temp == x1)
        {
            printf("%d ", x2);
        }
        else
        {
            printf("%d ", x1);
        }
        if (y_temp == y1)
        {
            printf("%d", y2);
        }
        else
        {
            printf("%d", y1);
        }
    }
    return 0;
}