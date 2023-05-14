#include <stdio.h>

int main(void)
{
    int N = 0;
    int mac = 0;
    int col = 0;
    scanf("%d", &N);
    scanf("%d %d", &col, &mac);
    if (N >= col/2 + mac)
        printf("%d", col/2 + mac);
    else
        printf("%d", N);
}