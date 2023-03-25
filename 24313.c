#include <stdio.h>

int main(void)
{
    int a_0 = 0;
    int a_1 = 0;
    int c = 0;
    int n_0 = 0;
    scanf("%d %d", &a_1, &a_0);
    scanf("%d", &c);
    scanf("%d", &n_0);
    if ((a_1 <= c) && (a_1 * n_0 + a_0 <= c * n_0))
    {
        printf("1");
    }
    else
    {
        printf("0");
    }
}