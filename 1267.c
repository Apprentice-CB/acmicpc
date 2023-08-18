#include <stdio.h>

int main(void)
{
    int N = 0;
    int M = 0;
    int Y = 0;
    int in;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &in);
        M += (in / 60) + 1;
        Y += (in / 30) + 1;
        // if (in % 60 == 0)
        //     M += (in / 60);
        // else
        //     M += (in / 60) + 1;
        // if (in % 30 == 0)
        //     Y += (in / 30);
        // else
        //     Y += (in / 30) + 1;
    }
    M *= 15;
    Y *= 10;

    if (M < Y)
    {
        printf("M %d", M);
    }
    else if (M > Y)
    {
        printf("Y %d", Y);
    }
    else
    {
        printf("Y M %d", Y);
    }
}