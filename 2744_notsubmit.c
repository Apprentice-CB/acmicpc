#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char s[100];
    scanf("%s", s);
    for (int i = 0; i < strlen(s); i++)
    {
        if (islower(s[i]))
        {
            printf("%c", toupper(s[i]));
        }
        else
        {
            printf("%c", tolower(s[i]));
        }
    }
}