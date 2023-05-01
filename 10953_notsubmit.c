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
        scanf("%s", str);
        A = atoi(&str[0]);
        B = atoi(&str[2]);
        printf("%d\n", A+B);
    }
}