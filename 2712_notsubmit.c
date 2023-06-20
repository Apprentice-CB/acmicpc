#include <stdio.h>
#include <string.h>

int main(void)
{
    int T = 0;
    scanf("%d", &T);
    float input;
    char unit[5];
    for (int i = 0; i < T; i++)
    {
        scanf("%f %s", &input, unit);
        if (!strcmp(unit, "kg"))
        {
            printf("%.4f lb\n", 2.2046 * input);
        }
        else if (!strcmp(unit, "lb"))
        {
            printf("%.4f kg\n", 0.4536 * input);
        }
        else if (!strcmp(unit, "l"))
        {
            printf("%.4f g\n", 0.2642 * input);
        }
        else if (!strcmp(unit, "g"))
        {
            printf("%.4f l\n", 3.7854 * input);
        }
    }
}