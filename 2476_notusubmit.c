#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int main(void)
{
    int N = 0;
    int a = 0;
    int b = 0;
    int c = 0; 
    int big = 0;
    int temp = 0;

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        temp = 0;
        scanf("%d %d %d", &a, &b, &c);
        if (a == b && b == c)
        {
            temp = 10000 + a * 1000;
        }
        else if (a == b && b != c)
        {
            temp = 1000 + a * 100;
        }
        else if (a == c && a != b)
        {
            temp = 1000 + a * 100;
        }
        else if (b == c || a != b)
        {
            temp = 1000 + b * 100;
        }
        else if (a != b && b != c && a != c)
        {
            temp = 100 * max(max(a, b), c);
        }

        if (temp > big)
        {
            big = temp;
        }
    }
    printf("%d", big);
}