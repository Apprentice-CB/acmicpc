#include <stdio.h>
#include <math.h>
#include <string.h>

int check(char str)
{
    int num = 0;
    switch (str)
    {
        case '0':
        {
            num = 0;
            break;
        }
        case '1':
        {
            num = 1;
            break;
        }
        case '2':
        {
            num = 2;
            break;
        }
        case '3':
        {
            num = 3;
            break;
        }
        case '4':
        {
            num = 4;
            break;
        }
        case '5':
        {
            num = 5;
            break;
        }
        case '6':
        {
            num = 6;
            break;
        }
        case '7':
        {
            num = 7;
            break;
        }
        case '8':
        {
            num = 8;
            break;
        }
        case '9':
        {
            num = 9;
            break;
        }
        case 'A':
        {
            num = 10;
            break;
        }
        case 'B':
        {
            num = 11;
            break;
        }
        case 'C':
        {
            num = 12;
            break;
        }
        case 'D':
        {
            num = 13;
            break;
        }
        case 'E':
        {
            num = 14;
            break;
        }
        case 'F':
        {
            num = 15;
            break;
        }
    }
    return num;
}

int main(void)
{
    char str[6];
    scanf("%s", str);
    int sum = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        sum = sum + check(str[i]) * (int)pow(16, (strlen(str)-1-i));
    }
    printf("%d", sum);
}