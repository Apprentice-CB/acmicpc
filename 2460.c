#include <stdio.h>

int main(void)
{
    int max = 0;
    int in = 0;
    int out = 0;
    int cur = 0;    
    for (int i = 0; i < 10; i++)
    {
        scanf("%d %d", &out, &in);
        cur = cur + in - out;
        if (cur > max)
        {
            max = cur;
        }
    }
    printf("%d", max);
}