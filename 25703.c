#include <stdio.h>

int main(void)
{
    int N = 0;
    scanf("%d", &N);
    printf("int a;\n");
    for (int i = 0; i < N; i++)
    {
        printf("int ");
        for (int j = 0; j <= i; j++)
        {
            printf("*");
        }
        if (i == 0)
        {
            printf("ptr = &a;\n");
        }
        else if (i == 1)
        {
            printf("ptr2 = &ptr;\n");
        }
        else
        {
            printf("ptr%d = &ptr%d;\n", i+1, i);
        }
            
    }
}