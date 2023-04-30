#include <stdio.h>
#include <string.h>

char stack[100];
int top = -1;

int main(void)
{
    char str[100];
    while(1)
    {
        top = -1;
        gets(str);
        if (!strcmp(str, "."))
        {
            break;
        }
        for (int i = 0; i < strlen(str); i++)
        {
            if (str[i] == '[' || str[i] == '(')
            {
                top++;
                stack[top] = str[i];
            }
            else if (str[i] == ']')
            {
                if (top < 0)
                {
                    top++;
                    break;
                }
                if (stack[top] == '[')
                {
                    top--;
                }
                else
                {
                    break;
                }
            }
            else if (str[i] == ')')
            {
                if (top < 0)
                {
                    top++;
                    break;
                }
                if (stack[top] == '(')
                {
                    top--;
                }
                else
                {
                    break;
                }
            }
        }
        if (top == -1)
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
    }
}