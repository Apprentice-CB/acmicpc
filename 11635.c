#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int N = 0;
    scanf("%d", &N);
    if (N == 1)
    {
        return 0;
    }
    int nominator = 2;
    int temp = N;
    while (N > 1)
    {
        while (N % nominator != 0)
        {
            nominator++;
        }
        
        N = N / nominator;
        printf("%d\n", nominator);
        nominator = 2;
    }
    return 0;
}