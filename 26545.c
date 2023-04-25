#include <stdio.h>

int main(void)
{
    int n = 0;
    int in = 0;
    int sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &in);
        sum += in;
    }
    printf("%d", sum);
}