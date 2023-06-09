#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char S[101];
    scanf("%s", S);
    int al[26] = {0, };
    for (int i = 0; i < strlen(S); i++)
    {
        al[S[i]-'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        printf("%d ", al[i]);
    }
}