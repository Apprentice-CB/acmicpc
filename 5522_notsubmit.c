#include <stdio.h>

int main(void)
{
    int sum = 0;
    int in = 0;
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &in);
        sum += in;
    }
    printf("%d", sum);
}