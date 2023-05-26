#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    int N = 0;
    char s[20];
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%s", s);
        for (int j = 0; j < strlen(s); j++)
        {
            printf("%c", tolower(s[j]));
        }
        printf("\n");
    }
}