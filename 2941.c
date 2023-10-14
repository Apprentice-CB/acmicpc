#include <stdio.h>
#include <string.h>

char str[110];

int main(void)
{
    int cnt = 0;
    scanf("%s", str);
    for (int i = 0; i < strlen(str); i++)
    {
        // printf("str[%d]:%c\n", i, str[i]);
        if (str[i] == 'c')
        {
            if (i+1 < strlen(str) && str[i+1] == '=') 
            {
                i++;
            }
            else if (i+1 < strlen(str) && str[i+1] == '-') 
            {
                i++;
            }
        }
        else if (str[i] == 'd')
        {
            if (i+1 < strlen(str) && str[i+1] == 'z')
            {
                if (i+2 < strlen(str))
                {
                    if (str[i+2] == '=') 
                    {
                        i = i + 2;
                    }
                }
            }
            else if (i+1 < strlen(str) && str[i+1] == '-') 
            {
                i++;
            }
        }
        else if (str[i] == 'l' || str[i] == 'n')
        {
            if (i+1 < strlen(str) && str[i+1] == 'j') 
            {
                i++;
            }
        }
        else if (str[i] == 's' || str[i] == 'z')
        {
            if (i+1 < strlen(str) && str[i+1] == '=') 
            {
                i++;
            }
        }
        cnt++;
    }
    printf("%d\n", cnt);
}