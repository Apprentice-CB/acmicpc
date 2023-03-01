#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
    int N = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i = i + 4)
    {
        printf("long ");
    }
    printf("int\n");
    return 0;
}