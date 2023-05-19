#include <stdio.h>

int main(void)
{
    int N = 0;
    scanf("%d", &N);
    int a = 0;
    int cu = 0;
    int ncu = 0;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a);
        if (a == 0)
        {
            ncu++;
        }
        else
        {
            cu++;
        }
    }
    if (ncu > cu)
    {
        printf("Junhee is not cute!");
    }
    else
    {
        printf("Junhee is cute!");
    }
}