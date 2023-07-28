#include <stdio.h>
#include <string.h>

int main(void)
{
    char l[501];
    while (1)
    {
        scanf(" %[^\n]s", l);
        if (!strcmp(l, "END"))
        {
            return 0;
        }
        for (int i = strlen(l)-1; i >= 0; i--)
        {
            printf("%c", l[i]);
        }
        printf("\n");
    }
}