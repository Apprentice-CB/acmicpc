#include <stdio.h>

int main(void)
{   
    int M = 1;
    int F = 1;
    while (1)
    {
        scanf("%d %d", &M, &F);
        if (M==0 && F==0)
        {
            break;
        }
        printf("%d\n", M+F);
    }
}
