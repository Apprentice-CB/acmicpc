#include <stdio.h>
#include <string.h>

int main(void)
{
    char i[256];
    int mo = 0;
    while(1)
    {
        scanf(" %[^\n]s", i);
        mo = 0;
        if (!strcmp(i, "#"))
        {
            return 0;
        }
        for (int n = 0; n < strlen(i); n++)
        {
            if (i[n] == 'a' || i[n] == 'e' || i[n] == 'i' || i[n] == 'o' || i[n] == 'u' ||
            i[n] == 'A' || i[n] == 'E' || i[n] == 'I' || i[n] == 'O' || i[n] == 'U')
            {
                mo++;
            }
        }
        printf("%d\n", mo);
    }
}