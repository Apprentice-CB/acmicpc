#include <stdio.h>

int main(void)
{
    int T = 0;
    scanf("%d", &T);
    if (T % 10 != 0)
    {
        printf("-1\n");
        return 0;
    }
    int A = 0;
    int B = 0;
    int C = 0;
    A = A + T / 300;
    T = T % 300;
    B = B + T / 60;
    T = T % 60;
    C = C + T / 10;
    printf("%d %d %d", A, B, C);
    return 0;
}