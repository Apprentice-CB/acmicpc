#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[100];
    char oper;
    char str2[100];
    scanf("%s %c %s", str1, &oper, str2);
    if (oper == '+')
    {
        if (!strcmp(str1, str2))
        {
            printf("2");
            for (int i = 1; i < strlen(str1); i++)
            {
                printf("0");
            }
        }
        else
        {
            if (strlen(str1) > strlen(str2))
            {
                printf("1");
                for (int i = 0; i < strlen(str1)-strlen(str2)-1; i++)
                {
                    printf("0");
                }
                printf("1");
                for (int i = 0; i < strlen(str2)-1; i++)
                {
                    printf("0");
                }
            }
            else
            {
                printf("1");
                for (int i = 0; i < strlen(str2)-strlen(str1)-1; i++)
                {
                    printf("0");
                }
                printf("1");
                for (int i = 0; i < strlen(str1)-1; i++)
                {
                    printf("0");
                }
            }
        }
    }
    else if (oper == '*')
    {
        printf("1");
        for (int i = 0; i < strlen(str1)+strlen(str2)-2; i++)
        {
            printf("0");
        }
    }
}