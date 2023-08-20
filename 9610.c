#include <stdio.h>

int main(void)
{
    int n = 0;
    int x = 0;
    int y = 0;
    int q1 = 0;
    int q2 = 0;
    int q3 = 0;
    int q4 = 0;
    int axis = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &x, &y);
        if (x == 0 || y == 0)
        {
            axis++;
        }
        else if (x > 0 && y > 0)
        {
            q1++;
        }
        else if (x > 0 && y < 0)
        {
            q4++;
        }
        else if (x < 0 && y > 0)
        {
            q2++;
        }
        else
        {
            q3++;
        }
    }
    printf("Q1: %d\nQ2: %d\nQ3: %d\nQ4: %d\nAXIS: %d\n", q1, q2, q3, q4, axis);
    return 0;

}