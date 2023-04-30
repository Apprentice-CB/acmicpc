#include <stdio.h>

int main(void)
{
    int fibo[41][2];
    int T = 0;
    scanf("%d", &T);
    fibo[0][0] = 1;
    fibo[0][1] = 0;
    fibo[1][0] = 0;
    fibo[1][1] = 1;
    for (int i = 2; i < 41; i++)
    {
        fibo[i][0] = fibo[i-1][0] + fibo[i-2][0];
        fibo[i][1] = fibo[i-1][1] + fibo[i-2][1];
    }

    int s = 0;
    for (int i = 0; i < T; i++)
    {
        scanf("%d", &s);
        printf("%d %d\n", fibo[s][0], fibo[s][1]);
    }
}