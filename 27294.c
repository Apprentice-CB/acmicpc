#include <stdio.h>

int main(void)
{
    int T, S;
    scanf("%d %d", &T, &S);
    if (T <= 11 || 16 < T || S == 1) // 점심이 아니면서
    {
        printf("280\n");
    }
    else if ((12 <= T && T <= 16) && S == 0)
    {
        printf("320\n");
    }
    return 0;
}