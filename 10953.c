#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char str[3];
    int N = 0;
    scanf("%d", &N);
    int A = 0;
    int B = 0;
    for (int i = 0; i < N; i++)
    {
        scanf("%d,%d", &A, &B);
        printf("%d\n", A+B);
    }
}