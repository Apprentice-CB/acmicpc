#include <stdio.h>

int main(void)
{
    int total = 0;
    int min = 0;
    scanf("%d", &total);
    for (int i = 0; i < 9; i++)
    {
        scanf("%d", &min);
        total = total - min;
    }
    printf("%d", total);
}