#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char t;
    char sent[255];
    int cnt = 0;
    while(1)
    {
        cnt = 0;
        scanf(" %[^\n]", sent);        
        if (sent[0] == '#')
        {
            return 0;
        }

        for (int i = 2; i < strlen(sent); i++)
        {
            if (sent[i] == sent[0] || tolower(sent[i]) == sent[0])
            {
                cnt++;
            }
        }
        printf("%c %d\n",sent[0], cnt);
    }
}