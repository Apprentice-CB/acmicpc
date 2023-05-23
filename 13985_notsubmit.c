#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char st[10];
    scanf(" %[^\n]s", st);
    if (atoi(&st[0]) + atoi(&st[4]) == atoi(&st[8]))
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
}