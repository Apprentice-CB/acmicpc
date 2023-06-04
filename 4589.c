#include <stdio.h>

int main(void)
{
    int N = 0;
    int a = 0;
    int b = 0;
    int c = 0;
    scanf("%d", &N);
    printf("Gnomes:\n");
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        if ((a <= b && b <= c ) || (c <= b && b <= a))
        {
            printf("Ordered\n");
        }
        else
        {
            printf("Unordered\n");
        }
    }
}