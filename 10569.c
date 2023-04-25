#include <stdio.h>

int main(void)
{
    int T = 0;
    int V = 0;
    int E = 0;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%d %d", &V, &E);
        printf("%d\n", 2 + E - V);
    }
}