#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[333335];
    scanf("%s", str);
    int len = strlen(str);
    if (str[0] == '1')
    {
        printf("1");
    }
    else if (str[0] == '2')
    {
        printf("10");
    }
    else if (str[0] == '3')
    {
        printf("11");
    }
    else if (str[0] == '4')
    {
        printf("100");
    }
    else if (str[0] == '5')
    {
        printf("101");
    }
    else if (str[0] == '6')
    {
        printf("110");
    }
    else if (str[0] == '7')
    {
        printf("111");
    }
    if (len == 1 && str[0] == '0') printf("0");
    
    for (int i = 1; i < len; i++)
    {
        if (str[i] == '0')
        {
            printf("000");
        }
        else if (str[i] == '1')
        {
            printf("001");
        }
        else if (str[i] == '2')
        {
            printf("010");
        }
        else if (str[i] == '3')
        {
            printf("011");
        }
        else if (str[i] == '4')
        {
            printf("100");
        }
        else if (str[i] == '5')
        {
            printf("101");
        }
        else if (str[i] == '6')
        {
            printf("110");
        }
        else if (str[i] == '7')
        {
            printf("111");
        }
    }
}